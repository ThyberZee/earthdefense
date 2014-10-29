#include <vector>
#include <string>
#include <QDebug>

#include "projectile.h"
#include "gamemodel.h"
#include "enemy.h"

GameModel GameModel::instance;

GameModel::GameModel(){}

void GameModel::initializeGame(){
    player = new Player(5,5);
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
        player = new Player(x,y);

        return player;
    }else if(type == "enemy"){
        Enemy* e = new Enemy(x,y);
        entities.push_back(e);

        return e;
    }else if(type == "bullet"){
        Projectile* p = new Projectile(x,y);
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
    return NULL;
}

GameModel::~GameModel(){
    for(Entity* e: entities){
        delete e;
    }
    delete player;
}
