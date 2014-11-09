#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QDebug>
#include <QWidget>
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
    int window_height, window_width; //these two variables set in intitializer
    int score, spawnCountDown;

public:
    ~GameModel();

    void initializeGame();
    void reset();

    string state();
    void loadGame(QString filename);
    void saveGame(string filename);

    void update();

    Entity* create(string type, int x, int y, int dir=-1);
    Entity* getById(int id);
    Entity* destroy(int id);

    //getters and setters
    Player* getPlayer(){return player;}
    vector<Entity*> getEntities(){return entities;}
    int getScore(){ return score;}
    void setScore(int s){score = s;}


    /***  singleton implementation ****/
private:
    static GameModel instance;
    GameModel();
public:
    static GameModel &getInstance() {
        return instance;
    }
};

#endif // GAMEMODEL_H
