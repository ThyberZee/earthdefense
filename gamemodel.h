#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QWidget>
#include "gamemodel.h"

class WorldEntity;
class Bullet;

class GameModel {

    //Player player; //Joshua

public:
    GameModel(QWidget* parent);
    ~GameModel();

    // sets up initial game settings
    void initializeGame();

    void updateShipPos(WorldEntity);

    void updateBulletPos(Bullet);

    // eventually....
    void updateBackground(QWidget* parent);

    // pretty much calls the Load class (Which Matt is making?)
    void loadGame(std::string filename);

    // pretty much calls the Save class "                      "
    void saveGame(/*NEED TO PUT SOMETHING HERE :)*/);

};

#endif // GAMEMODEL_H
