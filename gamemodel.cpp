#include <vector>
#include <string>
#include <QDebug>

#include "projectile.h"
#include "gamemodel.h"
#include "entity.h"
#include "enemy.h"
#include "player.h"


GameModel GameModel::instance;

GameModel::GameModel(){}

void GameModel::initializeGame(){
    QPoint point(5,5);
    player = new Player(point);
}

void GameModel::reset(){

    //reset player
    delete player;
    player = nullptr;

    //delete all entities
    for(Entity* e: entities){
        delete e;
    }
    entities.clear();
}


//save state of all entities
void GameModel::saveGame(string filename){
    ofstream outfile(filename);
    for(Entity* e: entities){
        e->save(outfile);
    }

    player->save(outfile);
    outfile.close();
}


void GameModel::loadGame(string filename){
    string type;
    int x;
    int y;

    ifstream infile(filename);
    while(infile){
        infile >> type;
        infile >> x;
        infile >> y;

        create(type,x,y);
    }
    infile.close();
}

Entity *GameModel::create(string type, int x, int y){

    if(type == "player"){
        delete player;
        player = new Player(QPoint(x,y));

        return player;
    }else if(type == "enemy"){
        QPoint tempPoint(x,y);
        Enemy* e = new Enemy(tempPoint);
        entities.push_back(e);

        return e;
    }else if(type == "bullet"){
        QPoint tempPoint(x,y);
        Projectile* p = new Projectile(tempPoint,50);
        entities.push_back(p);

        return p;
    }else{
        return nullptr;
    }
}

Entity* GameModel::getById(int id) {
    for (size_t i = 0; i < entities.size(); ++i) {
        Entity* obj = entities.at(i);
        if (obj->getId() == id) {
            return obj;
        }
    }
    return nullptr;
}

GameModel::~GameModel(){
    for(Entity* e: entities){
        delete e;
    }
    delete player;
}
