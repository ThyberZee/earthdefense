#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <string>
#include <vector>
#include <QWidget>

#include "player.h"
#include "entity.h"

using namespace std;

//abstract game model class
class GameModel {
private:
    vector<Entity*> entities;
    Player* player;

public:
    GameModel();
    ~GameModel();

    void initializeGame();
    void spawn(int x, int y, int s);

    void loadGame(string filename);
    void saveGame(string filename);

};

#endif // GAMEMODEL_H
