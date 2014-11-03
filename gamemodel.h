#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QDebug>
#include <QWidget>
#include <string>
#include <vector>
#include "projectile.h"
#include "gamemodel.h"
#include "enemy.h"
#include "player.h"
#include "entity.h"

using namespace std;

//abstract game model class
class GameModel {
private:
    vector<Entity*> entities;
    Player* player;
    int window_height;
    int window_window;

public:
    GameModel();
    ~GameModel();

    void initializeGame();
    void reset();

    string state();
    void loadGame(string filename);
    void saveGame(string filename);

    void update();

    Entity* create(string type, int x, int y);
    Entity* getById(int id);
    Entity* destroy(int id);

    //getters and setters
    Player* getPlayer(){return player;}
    vector<Entity*> getEntities(){return entities;}


    /***  singleton implementation ****/
private:
    static GameModel instance;
public:
    static GameModel &getInstance() {
        return instance;
    }
};

#endif // GAMEMODEL_H
