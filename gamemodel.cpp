#include <vector>
#include <string>

#include "gamemodel.h"
#include "enemy.h"

GameModel GameModel::instance;

GameModel::GameModel(){
    //test
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

        if(type == "player"){
            //don't forget to delete old player
            delete player;
            player = new Player(x,y);
        }else{
            entities.push_back(new Enemy(x,y,100));
        }
    }
    infile.close();
}

void GameModel::spawn(int x, int y, int s)
{
    entities.push_back(new Enemy(x,y,s));
}

GameModel::~GameModel(){
    for(Entity* e: entities){
        delete e;
    }
    delete player;
}
