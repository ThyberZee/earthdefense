#include "ingame.h"

using namespace std;

InGame::InGame(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::InGame)
{
    ui->setupUi(this);

    //start gamemodel
    GameModel::getInstance().initializeGame();
    fpsTimer = new QTimer(this);

    //Timer->setInterval(1000/30.0); // Original 30 frames
    fpsTimer->setInterval(1000/60.0); // EXPERIMENT: 60 frames

    connect(fpsTimer, &QTimer::timeout, this, &InGame::updateView);

    pl = new PlayerWidget(this);

    pl->show();
    fpsTimer->start();

}

InGame::~InGame()
{
    delete ui;
}

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

    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(0);
    }else if (ev->key() == 0x01000014){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(0);
    }
}

void InGame::updateView() {
    qDebug(GameModel::getInstance().state().c_str());
    vector<Entity*> entities = GameModel::getInstance().getEntities();

    GameModel::getInstance().update();


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
                                        10,                                      //BULLET_WIDTH
                                        30));


                //check for type in order to set proper image.  right now just sets text
                if(temp->getProjectile()->toString().find("projectile") == 0){
                    temp->setText("P");
                }else{
                    temp->setText("E");
                }

                temp->show();

                entity->setJustCreated(false);  //make sure we know that entity is no longer new.
        }
    }

    //update each remaining widget

    for(size_t i = 0; i < ewidgets.size(); i++){
        EntityWidget *wdgt = ewidgets.at(i);
        if (wdgt->getProjectile()->isAlive() == false){
            entities.erase(entities.begin()+i);
            delete wdgt;
        }else{
            wdgt->move(wdgt->getProjectile()->getPos().x(),wdgt->getProjectile()->getPos().y());
            wdgt->show();
        }
    }
}

