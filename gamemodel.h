#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QWidget>
#include "gamemodel.h"

class Ship;
class Bullet;

class GameModel {
    Ship* ship;
    // not sure what to do here, mabye some kind of configuration file that
    // contains all the info of a Game State? In that case, GameStateType would
    // be something like an ofstream file object.
    //GameStateType state; // <---- probably should fix this soon

public:
    GameModel(QWidget* parent);
    ~GameModel();

    // sets up initial game settings
    void initializeGame();

    void updateShipPos(Ship);

    void updateBulletPos(Bullet);

    // eventually....
    void updateBackground(QWidget* parent);

    // pretty much calls the Load class (Which Matt is making?)
    void loadGame(std::string filename);

    // pretty much calls the Save class "                      "
    void saveGame(GameStateType state);

};

#endif // GAMEMODEL_H
