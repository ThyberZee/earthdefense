#include "ingame.h"
#include "ui_ingame.h"
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <typeinfo>

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

    //Josh experiment
    pl = new PlayerWidget(this);

    pl->show();
    fpsTimer->start();

}

InGame::~InGame()
{
    delete ui;
}

void InGame::keyPressEvent(QKeyEvent *ev){
    //JOSH EXPERIMENT
    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(-1);

    }else if (ev->key() == 0x01000014){ //right key pressed
        GameModel::getInstance().getPlayer()->setDir(1);

    }else if (ev->key() == 0x20){ // space key pressed
        int x = GameModel::getInstance().getPlayer()->getPos().x();
        int y = GameModel::getInstance().getPlayer()->getPos().y();

        GameModel::getInstance().create("projectile",x,y);
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
    vector<Entity*> entities = GameModel::getInstance().getEntities();

    /* Jared to Josh -> I think this needs to go into Game model,
     *being driven by the master timer in the model (which drives the model)
     *pretty much the model takes care of itself, the view just taps into it.
     *The only thing in the model that the view can change is in the functions
     *above: key events and the initialization of the game model in the constructor.
     *The view will have its own Timer driving it, calling this function (updateView).
     *   ---open to discussion :}
     */
    GameModel::getInstance().update();


    /* Update PlayerWidget Position */
    pl->setGeometry(QRect(
             pl->getPlayer()->getPos().x(),
             pl->getPlayer()->getPos().y(),
             100, 100));
    pl->show();

    /* Update BulletWidget and EnemyWidget Postions */
    for (Entity* i : entities) {

        if (i->toString().find("projectile")){ // if i is of type Projectile...
            if (i->getJustCreated()) {         // returns true if the projectile was JUST created
                ProjectileWidget* temp = new ProjectileWidget(this, dynamic_cast<Projectile*>(i));
                pr.push_back(temp);
                i->setJustCreated(false);
            }

            for (size_t i = 0; i < pr.size(); i++) {
                ProjectileWidget* bullet = pr.at(i);
                bullet->setGeometry(QRect(bullet->getBullet()->getPos().x(),   //initially halfway across the player object, so player.x() + player.width/2 (pl)
                                          bullet->getBullet()->getPos().y(),   //should be a constant distance...probably HEIGHT_OF_BULLET + 1, so it starts just above pl
                                          10,                                  //WIDTH_OF_BULLET
                                          30));                                //HEIGHT_OF_BULLET
                bullet->show();
                if (bullet->getBullet->getPos().y() > 800) {   // If the bullet goes off the screen
                    bullet->getBullet->kill();                 // delete the underlyine object (should be done in model)
                    pr.erase(i);                               // delete the widget out of the pr vector

                }

            }

        } else if (i->toString().find("enemy")) {
            //TODO
        }
    }
}
