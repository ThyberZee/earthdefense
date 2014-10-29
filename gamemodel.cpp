#include <vector>
#include <string>

#include "gamemodel.h"
#include "entity.h"
#include "enemy.h"
#include "player.h"

GameModel::GameModel(){
    //test
    /* for some reason, this was giving me compile errors --- Jared */
    QPoint* point = new QPoint(5,5);
    Player* player = new Player(point);
}

void GameModel::reset(){
    //BUGGY (I think)
    delete player;
    player = nullptr;

    for(Entity* e: entities){
        delete e;
    }
    //does clear really clear?
    // - Jared -> Yes
    entities.clear();
}

void GameModel::saveGame(string filename){
    ofstream outfile(filename);

    for(Entity* e: entities){
        e->save(outfile);
    }

    player->save(outfile);
    outfile.close();
}

void GameModel::loadGame(string filename){
    //doing the deletions and stuff should go in a reset function
    entities.clear();
    string type;
    int x;
    int y;
    ifstream infile(filename);
    infile >> type;
    infile >> x;
    infile >> y;

    if(type == "player"){
        //don't forget to delete old player

        player = new Player(new QPoint(x,y));
    }else{
        entities.push_back(new Enemy(new QPoint(x,y),100));
    }
}
void GameModel::spawn(int x, int y, int s)
{
    entities.push_back(new Enemy(new QPoint(x,y),s));
}

GameModel::~GameModel(){
    for(Entity* e: entities){
        delete e;
    }
    delete player;
}
