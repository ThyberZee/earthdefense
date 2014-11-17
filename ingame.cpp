#include "ingame.h"
#include "client.h"
#include "host.h"
#include "gameover.h"

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

    //start timer
    fpsTimer = new QTimer(this);
    fpsTimer->setInterval(1000/50.0);
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
// model?  basically, instead of acting directly on a keydown or up, just call the
// appropriate method in the input manager to set the flag.  Then, inside the model
// check the input managers state, and perform the appropriate action.

void InGame::keyPressEvent(QKeyEvent *ev){

    if (ev->key() == 0x01000012){ //left key pressed
        if(netstatus == "client") {
            Client::getInstance().sendMessage("left down");
        }else{
            GameModel::getInstance().getPlayer()->setDir(-1);
        }
        //InputManager::getInstance().keyDown("left");

    }else if (ev->key() == 0x01000014){ //right key pressed
        if(netstatus == "client") {
            Client::getInstance().sendMessage("right down");
        }else{
            GameModel::getInstance().getPlayer()->setDir(1);
        }
        //InputManager::getInstance().keyDown("right");


    }else if (ev->key() == 0x20){ // space key pressed
        if(netstatus == "client"){
            Client::getInstance().sendMessage("fire down");
        }else{
            int x = GameModel::getInstance().getPlayer()->getPos().x() + 22;
            int y = GameModel::getInstance().getPlayer()->getPos().y() - 10;

            GameModel::getInstance().create("projectile", x, y);
        }
        //InputManager::getInstance().keyDown("fire");
    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {

    if (ev->key() == 0x01000012){ // left key released
         if(netstatus == "client") {
             Client::getInstance().sendMessage("left up");
         }else{
             GameModel::getInstance().getPlayer()->setDir(0);
         }
        //InputManager::getInstance().keyUp("left");              // NEW

    }else if (ev->key() == 0x01000014){ // right key released

         if(netstatus == "client") {
             Client::getInstance().sendMessage("right up");
         }else{
             GameModel::getInstance().getPlayer()->setDir(0);
         }
    }
}


/* * * * * * * * * * * * * * * * * * * * *
 *         MAIN UPDATE FUNCTION          *
 * * * * * * * * * * * * * * * * * * * * */


void InGame::updateView() {
    //set score label
    ui->scorelbl->setText(QString::number(GameModel::getInstance().getScore()));
    ui->lblNetstatus->setText(netstatus);


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
                //not sure why, but dynamic casting is necessary for this one.
                dynamic_cast<Player*>(temp);
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
            entity->setJustCreated(false);  //make sure we know that entity is no longer new.
        }
    }

    //update each remaining widget

    for(size_t i = 0; i < ewidgets.size(); i++){
        EntityWidget *wdgt = ewidgets.at(i);
        if (wdgt->getEntity()->isAlive() == false){     //destroy widget if corresponding entity is dead
            //explosions!!!

                if((wdgt->getExpCount() >= 0 && wdgt->getExpCount() < 5) || (wdgt->getExpCount() >= 40 && wdgt->getExpCount() < 45)){
                    wdgt->setPixmap(QPixmap(":/resources/images/explosion0.png"));
                    wdgt->incExpCount();
                }else if((wdgt->getExpCount() >= 5 && wdgt->getExpCount() < 10) || (wdgt->getExpCount() >= 35 && wdgt->getExpCount() < 40)){
                    wdgt->setPixmap(QPixmap(":/resources/images/explosion1.png"));
                    wdgt->incExpCount();
                }else if((wdgt->getExpCount() >= 10 && wdgt->getExpCount() < 15) || (wdgt->getExpCount() >= 30 && wdgt->getExpCount() < 35)){
                    wdgt->setPixmap(QPixmap(":/resources/images/explosion2.png"));
                    wdgt->incExpCount();
                }else if((wdgt->getExpCount() >= 15 && wdgt->getExpCount() < 20) || (wdgt->getExpCount() >= 25 && wdgt->getExpCount() < 30)){
                    wdgt->setPixmap(QPixmap(":/resources/images/explosion3.png"));
                    wdgt->incExpCount();
                }else if(wdgt->getExpCount() >= 20 && wdgt->getExpCount() < 25){
                    wdgt->setPixmap(QPixmap(":/resources/images/explosion4.png"));
                    wdgt->incExpCount();
                }else{
                    ewidgets.erase(ewidgets.begin()+i);
                    delete wdgt;
                }
        }else{
            wdgt->move(wdgt->getEntity()->getPos().x(),wdgt->getEntity()->getPos().y());
            wdgt->show();
        }
    }
}

void InGame::gameOver(){
    fpsTimer->stop();
    //QMessageBox
    Gameover* gameWindow = new Gameover(this,GameModel::getInstance().getScore());
    gameWindow->show();
    gameWindow->setEnabled(true);
    this->hide();
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

//hide this window and create a new ingame, passing in the same params.
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
