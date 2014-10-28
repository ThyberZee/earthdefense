#include "gamemodel.h"
#include "enemy.h"

GameModel::GameModel(){
    //test
    player = new Player(5,5);
}

void GameModel::saveGame(string filename){
    ofstream outfile(filename);

    for(Entity* e: entities){
        e->save(outfile);
    }

    player->save(outfile);
    outfile.close();
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
