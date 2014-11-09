#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QDebug>
#include <QWidget>
#include <QString>
#include <vector>
#include <sstream>
#include "host.h"
#include "projectile.h"
#include "gamemodel.h"
#include "enemy.h"
#include "player.h"
#include "entity.h"
#include "sstream"

using namespace std;

//abstract game model class
class GameModel {
private:
    vector<Entity*> entities;
    Player* player;
    Player* player2;
    int window_height;
    int window_width;
    int score;
    int spawnCountDown;

public:
    GameModel();
    ~GameModel();

    void initializeGame();
    void reset();

    string state();
    void loadGame(string filename);
    void saveGame(string filename);

    void masterUpdate();
    void slaveUpdate();

    Entity* create(string type, int x, int y, int dir=-1);
    Entity* getById(int id);
    Entity* destroy(int id);

    //getters and setters
    Player* getPlayer(){return player;}
    vector<Entity*> getEntities(){return entities;}
    int getScore(){ return score;}
    void setScore(int s){score = s;}


    /***  singleton implementation ***/
private:
    static GameModel instance;
public:
    static GameModel &getInstance() {
        return instance;
    }
};

#endif // GAMEMODEL_H
