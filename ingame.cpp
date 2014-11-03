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
    //JOSH EXPERIMENT
    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(-1);

    }else if (ev->key() == 0x01000014){ //right key pressed
        GameModel::getInstance().getPlayer()->setDir(1);

    }else if (ev->key() == 0x20){ // space key pressed
        int x = GameModel::getInstance().getPlayer()->getPos().x();
        int y = GameModel::getInstance().getPlayer()->getPos().y();

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


    /* Update PlayerWidget Position ---- MIGHT HAVE TO IMPLEMENT SAME AS BELOW WHEN WE INTRODUCE MULTIPLAYER SINCE THERE WILL BE MORE THAN
     *                                   ONE PLAYER ON THE SCREEN AT ONE TIME */
    pl->setGeometry(QRect(
             pl->getPlayer()->getPos().x(),
             pl->getPlayer()->getPos().y(),
             100, 100));
    pl->show();

    /* Update BulletWidget and EnemyWidget Postions */
//    for (Entity* entity_obj : entities) {

//        /////////////////////IF WIDGET IS PROJECTILE///////////////////////
//        if (entity_obj->toString().find("projectile")){ // if i is of type Projectile...
//            if (entity_obj->getJustCreated()) {         // returns true if the projectile was JUST created
//                ProjectileWidget* temp = new ProjectileWidget(this, dynamic_cast<Projectile*>(entity_obj));
//                pr.push_back(temp);
//                entity_obj->setJustCreated(false);
//            }

//            for (size_t j = 0; j < pr.size(); j++) {
//                ProjectileWidget* bullet = pr.at(j);
//                bullet->setGeometry(QRect(bullet->getProjectile()->getPos().x(),   //initially halfway across the player object, so player.x() + player.width/2 (pl)
//                                          bullet->getProjectile()->getPos().y(),   //should be a constant distance...probably HEIGHT_OF_BULLET + 1, so it starts just above pl
//                                          10,                                      //BULLET_WIDTH
//                                          30));                                    //BULLET_HEIGHT
//                bullet->show();
//                if (bullet->getProjectile()->isAlive() == false) {   // If the bullet goes off the screen
//                    delete bullet;
//                    pr.erase(pr.begin() + j);                               // delete the widget out of the pr vector

//                }
//            }


//        //////////////////////IF WIDGET IS ENEMY//////////////////////////
//        } else if (entity_obj->toString().find("enemy")) {
//            if (entity_obj->getJustCreated()) {
//                EnemyWidget* temp = new EnemyWidget(this, dynamic_cast<Enemy*>(entity_obj));
//                en.push_back(temp);
//                entity_obj->setJustCreated(false);
//            }

//            for (size_t i = 0; i < en.size(); i++) {
//                EnemyWidget* enemy = en.at(i);
//                enemy->setGeometry(QRect(enemy->getEnemy()->getPos().x(),
//                                          enemy->getEnemy()->getPos().y(),
//                                          100,      //ENEMY_WIDTH
//                                          100));    //ENEMY_HEIGHT
//                enemy->show();
//                if (enemy->getEnemy()->getPos().x() < 0 || enemy->getEnemy()->getPos().x() > 640 || // If the enemy goes off the screen in any
//                    enemy->getEnemy()->getPos().y() < 0 || enemy->getEnemy()->getPos().y() > 800)   // way shape or form....
//                {
//                    enemy->getEnemy()->kill();  // kill it (underlying object)
//                    en.erase(en.begin() + i);                // and erase it (EnemyWidget in vector en)
//                }
//            }
//        }
//    }

    for(Entity* entity:entities){
        if(entity->getJustCreated()){

            if (entity->toString().find("projectile")){
                EntityWidget* temp = new EntityWidget(this, dynamic_cast<Projectile*>(entity));
                ewidgets.push_back(temp);

                temp->setText("projectile");

                temp->setGeometry(QRect(entity->getPos().x(),   //initially halfway across the player object, so player.x() + player.width/2 (pl)
                                                         entity->getPos().y(),   //should be a constant distance...probably HEIGHT_OF_BULLET + 1, so it starts just above pl
                                                         10,                                      //BULLET_WIDTH
                                                       30));
                temp->show();
                entity->setJustCreated(false);      //make sure we know that entity is no longer new.
            }else if(entity->toString().find("enemy")){
                //do something
            }else if(entity->toString().find("player")){
                //do something else
            }
        }
    }

    for(size_t i = 0; i < ewidgets.size(); ++i){
        EntityWidget *wdgt = ewidgets.at(i);
        if (wdgt->getProjectile()->isAlive() == false){
            entities.erase(entities.begin()+i);
            delete wdgt;
        }else{
            wdgt->move(wdgt->getProjectile()->getPos().x(),wdgt->getProjectile()->getPos().y());
            wdgt->show();
        }
    }
/*
    for(QObject* qobj: this->children()){
        EntityWidget* wdgt = dynamic_cast<EntityWidget *>(qobj);
        if(wdgt->getProjectile()->isAlive() == false){
            delete wdgt;
        }

    }

    for(QObject* qobj: this->children()){
        EntityWidget* wdgt = dynamic_cast<EntityWidget *>(qobj);
        wdgt->move(wdgt->getProjectile()->getPos().x(),wdgt->getProjectile()->getPos().y());
        wdgt->show();
    }*/
}

