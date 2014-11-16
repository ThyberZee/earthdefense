#include "ingame.h"
#include "client.h"
#include "host.h"

using namespace std;

InGame::InGame(QMainWindow *parent, QString initLoadGameFile, QString netstat, int initDifficulty, QString initIp) :
    QMainWindow(parent),
    ui(new Ui::InGame),
    netstatus(netstat),
    difficulty(initDifficulty),
    ip(initIp)
{
    ui->setupUi(this);

    //start gamemodel

    GameModel::getInstance().setObserver(this);
    if (initLoadGameFile.size() != 0) {
        GameModel::getInstance().loadGame(initLoadGameFile);
    }

    GameModel::getInstance().setDifficulty(difficulty);
    GameModel::getInstance().initializeGame(netstat.toStdString());

    //init player widget
    Player* p = GameModel::getInstance().getPlayer();
    pl = new PlayerWidget(p,this);
    pl->setAttribute(Qt::WA_TranslucentBackground, true); //Transparency!!! :D
    GameModel::getInstance().getPlayer()->setDir(0);
    pl->show();

    if(netstat == "host"){
        Player* p = GameModel::getInstance().getPlayer2();
        pl2 = new PlayerWidget(p,this);
        pl2->setAttribute(Qt::WA_TranslucentBackground, true); //Transparency!!! :D
        GameModel::getInstance().getPlayer2()->setDir(0);
        pl2->show();
    }

    //start timer
    fpsTimer = new QTimer(this);
    fpsTimer->setInterval(1000/60.0);
    connect(fpsTimer, &QTimer::timeout, this, &InGame::updateView);
    fpsTimer->start();

    //server-client setup
    if(netstat == "client"){
        Client::getInstance().connectToServer(ip);
    }else if(netstat == "host"){
        Host::getInstance().start();

    }
}

InGame::~InGame()
{
    delete ui;
}


/* * * * * * * * * * * * * * * * * * * * * * * * *
 *               INPUT HANDLERS                  *
 * * * * * * * * * * * * * * * * * * * * * * * * */

// Matt, Can you try to abstract input handling away from the slots and into the
// model?  basicall, instead of acting directly on a keydown or up, just call the
// appropriate method in the input manager to set the flag.  Then, inside the model
// check the input managers state, and perform the appropriate action.

void InGame::keyPressEvent(QKeyEvent *ev){

    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(-1);
        if(netstatus == "client") {Client::getInstance().sendMessage("left down");}
        //InputManager::getInstance().keyDown("left");

    }else if (ev->key() == 0x01000014){ //right key pressed
        GameModel::getInstance().getPlayer()->setDir(1);
        if(netstatus == "client") {Client::getInstance().sendMessage("right down");}
        //InputManager::getInstance().keyDown("right");


    }else if (ev->key() == 0x20){ // space key pressed
        int x = GameModel::getInstance().getPlayer()->getPos().x() + 22;
        int y = GameModel::getInstance().getPlayer()->getPos().y() - 10;

        GameModel::getInstance().create("projectile", x, y);
        if(netstatus == "client") {Client::getInstance().sendMessage("fire down");}
        //InputManager::getInstance().keyDown("fire");
    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {

    if (ev->key() == 0x01000012){ // left key released
        GameModel::getInstance().getPlayer()->setDir(0);     // OLD

         if(netstatus == "client") {Client::getInstance().sendMessage("left up");}
        //InputManager::getInstance().keyUp("left");              // NEW

    }else if (ev->key() == 0x01000014){ // right key released
        GameModel::getInstance().getPlayer()->setDir(0);     // OLD
         if(netstatus == "client") {Client::getInstance().sendMessage("right up");}
        //InputManager::getInstance().keyUp("right");     // NEW

    }else if (ev->key() == 0x20){ // space key released
         if(netstatus == "client") {Client::getInstance().sendMessage("fire up");}
        //InputManager::getInstance().keyUp("fire");
    }
}

/* * * * * * * * * * * * * * * * * * * * *
 *         MAIN UPDATE FUNCTION          *
 * * * * * * * * * * * * * * * * * * * * */

void InGame::updateView() {
    //set score label
    ui->scorelbl->setText(QString::number(GameModel::getInstance().getScore()));


    //update game depending on whether game is multiplayer or singlplayer, host or client;
    if(netstatus == "client"){
        GameModel::getInstance().slaveUpdate();

    }else{
        GameModel::getInstance().masterUpdate();
        if(netstatus == "host"){
            Host::getInstance().sendMessage(QString::fromStdString(GameModel::getInstance().state()));
        }
    }

    //grab all entities and proceed to update their corresponding sprites.
    vector<Entity*> entities = GameModel::getInstance().getEntities();

    for(Entity* entity : entities){
        //if the ent is new, create new sprite;
        if(entity->getJustCreated()){
                EntityWidget* temp = new EntityWidget(this, entity);
                ewidgets.push_back(temp);

                temp->setGeometry(QRect(entity->getPos().x(),
                                        entity->getPos().y(),
                                        entity->width,
                                        entity->height));
                temp->setAttribute(Qt::WA_TranslucentBackground, true);

                //check for type in order to set proper image
                if(temp->getEntity()->toString().find("player") == 0){
                    QPixmap player(":/resources/images/Player.png");
                    temp->setPixmap(player);
                }else if(temp->getEntity()->toString().find("projectile") == 0){
                    QPixmap projectile(":/resources/images/projectile.png");
                    temp->setPixmap(projectile);
                } else if (temp->getEntity()->toString().find("trackingprojectile") == 0){
                    QPixmap trprojectile(":/resources/images/trackingmissle.png");
                    temp->setPixmap(trprojectile);
                } else if (temp->getEntity()->toString().find("enemy") == 0){
                    QPixmap enemy(":/resources/images/alien1.png");
                    temp->setPixmap(enemy);
                } else if (temp->getEntity()->toString().find("trackingenemy") == 0) {
                    QPixmap trenemy(":/resources/images/trackingenemy.png");
                    temp->setPixmap(trenemy);
                }
                temp->setScaledContents(true);
                temp->show();
                entity->setJustCreated(false);  //make sure we know that entity is no longer new.
        }
    }

    //update each remaining widget

    for(size_t i = 0; i < ewidgets.size(); i++){
        EntityWidget *wdgt = ewidgets.at(i);
        if (wdgt->getEntity()->isAlive() == false){     //destroy widget if corresponding entity is dead
            //explosions!!!
            ewidgets.erase(ewidgets.begin()+i);

            /*
            if( dynamic_cast<PlayerWidget*>(wdgt) == 0){
                //Work your magic, Sam!!
            }
            */

            delete wdgt;
        }else{
            wdgt->move(wdgt->getEntity()->getPos().x(),wdgt->getEntity()->getPos().y());
            wdgt->show();
        }
    }
}

void InGame::gameOver(){
    //fpsTimer->stop();
}

void InGame::advanceLevel() {
    ui->lblLevel->setText(QString(GameModel::getInstance().getCurrentLvl()));
}

/* * * * * * * * * * * *
 *       SLOTS         *
 * * * * * * * * * * * */

void InGame::on_btnSaveGame_clicked()
{

    GameModel::getInstance().saveGame("savegame");
}

void InGame::on_btnStartOver_clicked()
{
    this->hide();
    this->fpsTimer->stop();
    GameModel::getInstance().reset();
    GameModel::getInstance().initializeGame(netstatus.toStdString());
    InGame* newGameScreen = new InGame(this, "", netstatus, difficulty, ip);
    newGameScreen->show();
    newGameScreen->setEnabled(true);
}
