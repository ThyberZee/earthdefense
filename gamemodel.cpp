#include <vector>
#include <string>
#include <QDebug>

#include "projectile.h"
#include "gamemodel.h"
#include "entity.h"
#include "enemy.h"
#include "player.h"


GameModel GameModel::instance;

GameModel::GameModel(){
    initializeGame();
}

void GameModel::initializeGame(){
    QPoint point(270,500);
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

void GameModel::update(){
    player->update();
    for(Entity* e: entities){
        //kill the dead entities
        if (e->isAlive() == false){
            delete destroy(e->getId());
        }


        //update the rest
        e->update();
    }
}

//return a string representation of game state including pos data for each entity
string GameModel::state(){
    stringstream ss;
    for(Entity* e:entities){
        ss << e->toString() << endl;
    }
    ss << player->toString() << endl;
    return ss.str();
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

//return entity object of type specified.  returns null by default
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
    }else if(type == "projectile"){
        QPoint tempPoint(x,y);
        Projectile* p = new Projectile(tempPoint,50);
        entities.push_back(p);

        return p;
    }else{
        return NULL;
    }
}

//return pointer to object specified;  if it doesn't exist, return NULL
Entity* GameModel::getById(int id) {
    for (size_t i = 0; i < entities.size(); ++i) {
        Entity* obj = entities.at(i);
        if (obj->getId() == id) {
            return obj;
        }
    }
    return NULL;
}

//removes entity from entities if it exitsts, but DOES NOT DELETE
Entity* GameModel::destroy(int id) {
    for(size_t i = 0; i < entities.size(); ++i){
        Entity *obj = entities.at(i);
        if (obj->getId() == id){
            entities.erase(entities.begin()+i);
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
