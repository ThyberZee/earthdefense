#include "gamemodel.h"

GameModel GameModel::instance;

GameModel::GameModel(){
   //initializeGame();
}

void GameModel::initializeGame(){
    QPoint point(270,700); // need to change to variable
    player = new Player(point);
    spawnCountDown = rand() % 1000 + 1;  //set a countdown to random int from 1 to 100
}

void GameModel::reset(){

    //reset player
    delete player;
    player = nullptr;

    //delete all entities, then empties array
    for(Entity* e: entities){
        delete e;
    }
    entities.clear();
}

/*this is the most important function of the model.  It first updates the player,
 *then checks all of the enemies that called their kill function last frame, deleting
 *them and removing them from the vector.  Otherwise, it just updates the entity
 */
void GameModel::update(){
    player->update();
    for(size_t i = 0; i < entities.size(); i++){
        Entity* e = entities.at(i);
        //kill the dead entities
        if (e->isAlive() == false){
            entities.erase(entities.begin()+i);
            delete e;
        }else{
            e->update();    //update the rest
        }

        if(--spawnCountDown <= 0){
            create("enemy",rand()%500,rand()%500);
            spawnCountDown = rand() % 1000;
        }
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

/* save game state into file.  Format as follows:
 * entity0_type x y dir
 * entity1_type x y dir
 * etc.
 */
void GameModel::saveGame(string filename){
    ofstream outfile(filename);
    for(Entity* e: entities){
        e->save(outfile);
    }

    player->save(outfile);
    outfile.close();
}

//load game.  duh
void GameModel::loadGame(string filename){
    string type;
    int x;
    int y;
    int dir;    //direction is for projectiles. will be zero for player and enemy

    ifstream infile(filename);
    while(infile){
        infile >> type;
        infile >> x;
        infile >> y;
        infile >> dir;

        create(type,x,y,dir);
    }
    infile.close();
}

//return entity object of type specified.  returns null by default
Entity *GameModel::create(string type, int x, int y, int dir){

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
        Projectile* p = new Projectile(tempPoint,dir);
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
