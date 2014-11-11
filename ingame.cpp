#include "ingame.h"
#include "client.h"
#include "host.h"

using namespace std;

InGame::InGame(QMainWindow *parent, QString initLoadGameFile, bool client) :
    QMainWindow(parent),
    ui(new Ui::InGame),
    client(client)
{
    ui->setupUi(this);

    //start gamemodel
    GameModel::getInstance().setObserver(this);
    if (initLoadGameFile.size() != 0) {
        GameModel::getInstance().loadGame(initLoadGameFile);
    }
    GameModel::getInstance().initializeGame();

    //init player widget
    pl = new PlayerWidget(this);
    pl->setAttribute(Qt::WA_TranslucentBackground, true); //Transparency!!! :D
    pl->show();

    //start timer
    fpsTimer = new QTimer(this);
    fpsTimer->setInterval(1000/60.0);
    connect(fpsTimer, &QTimer::timeout, this, &InGame::updateView);
    fpsTimer->start();

    //server-client setup
    if(client){
        Client::getInstance().connectToServer();
    }else{
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

void InGame::keyPressEvent(QKeyEvent *ev){

    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(-1);

    }else if (ev->key() == 0x01000014){ //right key pressed
        GameModel::getInstance().getPlayer()->setDir(1);

    }else if (ev->key() == 0x20){ // space key pressed
        int x = GameModel::getInstance().getPlayer()->getPos().x() + 50;
        int y = GameModel::getInstance().getPlayer()->getPos().y() - 10;

        GameModel::getInstance().create("projectile", x, y);
    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {

    if (ev->key() == 0x01000012){ //left key released
        GameModel::getInstance().getPlayer()->setDir(0);
    }else if (ev->key() == 0x01000014){ //left key released
        GameModel::getInstance().getPlayer()->setDir(0);
    }
}

/* * * * * * * * * * * * * * * * * * * * *
 *         MAIN UPDATE FUNCTION          *
 * * * * * * * * * * * * * * * * * * * * */

void InGame::updateView() {
    //set score label
    QLabel* scorelabel = ui->scorelbl;
    QString s = QString::number(GameModel::getInstance().getScore());
    scorelabel->setText(s);

    //update game depending on whether game is multiplayer or singlplayer;
    if(client){
        GameModel::getInstance().slaveUpdate();
    }else{
        GameModel::getInstance().masterUpdate();
        Host::getInstance().sendMessage(QString::fromStdString(GameModel::getInstance().state()));
    }

    vector<Entity*> entities = GameModel::getInstance().getEntities();


    /* Update PlayerWidget Position ---- MIGHT HAVE TO IMPLEMENT SAME AS BELOW WHEN WE INTRODUCE MULTIPLAYER SINCE THERE WILL BE MORE THAN
     *                                   ONE PLAYER ON THE SCREEN AT ONE TIME */
    pl->setGeometry(QRect(pl->getPlayer()->getPos().x(),
                          pl->getPlayer()->getPos().y(),
                          100, 100));
    pl->show();


    for(Entity* entity : entities){
        if(entity->getJustCreated()){
                EntityWidget* temp = new EntityWidget(this, entity);
                ewidgets.push_back(temp);

                temp->setGeometry(QRect(entity->getPos().x(),   //initially halfway across the player object, so player.x() + player.width/2 (pl)
                                        entity->getPos().y(),   //should be a constant distance...probably HEIGHT_OF_BULLET + 1, so it starts just above pl
                                        entity->width,                                      //BULLET_WIDTH
                                        entity->height));
                temp->setAttribute(Qt::WA_TranslucentBackground, true);

                //check for type in order to set proper image
                if(temp->getEntity()->toString().find("projectile") == 0){
                    QPixmap projectile(":/resources/images/projectile.png");
                    temp->setPixmap(projectile);
                }else{
                    QPixmap theAlien(":/resources/images/alien1.png");
                    temp->setPixmap(theAlien);
                }

                temp->show();
                entity->setJustCreated(false);  //make sure we know that entity is no longer new.
        }
    }

    //update each remaining widget

    for(size_t i = 0; i < ewidgets.size(); i++){
        EntityWidget *wdgt = ewidgets.at(i);
        if (wdgt->getEntity()->isAlive() == false){     //destroy widget if corresponding entity is dead
            ewidgets.erase(ewidgets.begin()+i);
            delete wdgt;
        }else{
            wdgt->move(wdgt->getEntity()->getPos().x(),wdgt->getEntity()->getPos().y());
            wdgt->show();
        }
    }
}

void InGame::gameOver(){
    fpsTimer->stop();
}

/* * * * * * * * * * * *
 *       SLOTS         *
 * * * * * * * * * * * */

void InGame::on_pushButton_clicked()
{
    GameModel::getInstance().saveGame("savegame");
}
