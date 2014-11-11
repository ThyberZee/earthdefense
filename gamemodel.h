#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QDebug>
#include <QWidget>

#include <QString>
#include <vector>
#include <sstream>

#include "client.h"
#include "host.h"

#include "projectile.h"
#include "gamemodel.h"
#include "enemy.h"
#include "player.h"
#include "entity.h"
#include "sstream"
#include "worldobserver.h"

using namespace std;

//abstract game model class
class GameModel {
private:
    WorldObserver* observer;

    vector<Entity*> entities;
    Player* player;
    Player* player2;
    int window_height, window_width; //these two variables set in intitializer
    int score, spawnCountDown;

public:
    ~GameModel();

    void initializeGame();
    void gameOver();
    void reset();

    string state();
    void loadGame(QString filename);
    void saveGame(string filename);

    void masterUpdate();
    void slaveUpdate();

    Entity* create(string type, int x, int y, int dir=-1);
    Entity* getById(int id);
    Entity* destroy(int id);

    //getters and setters
    Player* getPlayer(){ return player;}
    Player* getPlayer2(){ return player2;}
    vector<Entity*> getEntities(){return entities;}
    int getScore(){ return score;}
    void setScore(int s){score = s;}
    void setObserver(WorldObserver* o){observer = o;}

    /***  singleton implementation ***/
private:
    static GameModel instance;
    GameModel();
public:
    static GameModel &getInstance() {
        return instance;
    }
};

#endif // GAMEMODEL_H
