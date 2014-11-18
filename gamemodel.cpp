#include "gamemodel.h"
#include "utils.h"

GameModel GameModel::instance;

GameModel::GameModel(): window_height(700), window_width(640) { }

//initialize game
void GameModel::initializeGame(string netstat){
    netstatus = netstat;
    if(netstatus == "client"){
        //player = new Player(point);
        return;
    }else{
        QPoint point((window_width/2) - 25 /*<---width of player widget*/  ,window_height - 50 /*<----width of player*/);
        player = new Player(point);
        entities.push_back(player);
        spawnCountDown = rand() % 300 + 1;  //set a countdown to random int from 1 to 30
        currentLvl = 0;
        //player2 = NULL;

        if(netstatus == "host"){
            player2 = new Player(QPoint(window_width/2-25, window_height - 50));
            entities.push_back(player2);
        }
    }
}

//reset game
void GameModel::reset(){

    //delete all entities, then empties array
    for(Entity* e: entities){
        delete e;
    }
    entities.clear();
    player = nullptr;
    player2 = nullptr;
    currentLvl = 0;
    score = 0;
}


/************************
 * For Advancing Levels *
 ************************/
bool GameModel::checkForNextLevel() {
    for (Entity* i : entities){
        if (i->toString().find("enemy") == 0 || i->toString().find("trackingenemy") == 0) {
            return false;
        }
    }
    return true;
}

void GameModel::advanceLevel() {
    QString filename = QString("Level%1").arg(++currentLvl);
    qDebug() << filename;
    loadGame(filename);
    observer->advanceLevel();
}


void GameModel::gameOver(){
    if(netstatus == "host"){
        Host::getInstance().sendMessage("gameover\n");
    }
    observer->gameOver();
    //reset();

}

/*this is the most important function of the model.  If their is a connected host,
 *it will check that and update player 2 accordingly. Then it updates player 1,
 *then checks all of the enemies that called their kill function last frame, deleting
 *them and removing them from the vector.  Otherwise, it just updates the entity
 */
void GameModel::masterUpdate(){
    string message = Host::getInstance().getMessage().toStdString();
    for(string line: split(message,'\n')){

        if(line == "") { continue; }

        if(line == "left down"){
            player2->setDir(-1);
        }else if(line == "right down"){
            player2->setDir(1);
        }else if(line == "fire down"){
            create("projectile", player2->getPos().x()+22,player2->getPos().y()-10);
        }else if(line == "right up" || "left up"){
            player2->setDir(0);
        }
    }


    for(size_t i = 0; i < entities.size(); i++){
        Entity* e = entities.at(i);
        //kill the dead entities
        if (e->isAlive() == false){
            entities.erase(entities.begin()+i);
            delete e;
        }else{
            e->update();    //update the rest
        }
    }

    /*Level Change*/
    if (checkForNextLevel()){
        advanceLevel();
    }

    //random spawning of enemies
    if(--spawnCountDown <= 0 && currentLvl > 4){
        if (rand()%2 == 0) {
            create("enemy", rand()%500,rand()%400);
        } else {
            create("trackingenemy", rand()%500, rand()%300);
        }

        spawnCountDown = rand() % 30;
    }
    if(cooldown > 0){
        cooldown--;
    }
}

/*
 * this method is what updates by reading network data.
 * it reads every line and updates the appropriate entities accordingly
 */
void GameModel::slaveUpdate(){
    string message = Client::getInstance().getMessage().toStdString();
    string type;
    int ID, x, y, dir;
    for(string line: split(message,'\n')){
        if(line == "") { continue; }

        stringstream stream(line);
        stream >> type;
        stream >> ID;
        stream >> x;
        stream >> y;
        stream >> dir;

        if(type == "gameover"){
            observer->gameOver();
        }else{
            Entity* ent = getById(ID);
            if(ent == NULL){
                Entity* e = create(type,x,y,dir);
                //this last if is a last-ditch check against lookup failure
                //it actually prevents segfaults, believe it or naw.
                if(e != NULL){
                    e->setId(ID);
                }
            }else if(type == "dead"){
                ent->kill();
            }else{
                ent->setPos( QPoint(x,y));
            }
        }
    }
    //yes, client needs to keep track of its own cooldown as well;
    if(cooldown > 0){
        cooldown--;
    }
}

//return a string representation of game state including pos data for each entity
string GameModel::state(){
    stringstream ss;
    for(Entity* e:entities){
        if(!e->isAlive()){
            ss << "dead " << e->getId() << endl;
        }else{
            ss << e->toString() << endl;
        }
    }
    return ss.str();
}

/* save game state into file.  Format as follows:
 * score
 * entity0_type id x y dir
 * entity1_type id x y dir
 * player       id x y dir
 * etc.
 */
void GameModel::saveGame(string filename){
    ofstream outfile(filename);
    outfile << "score " << score << endl;
    for(Entity* e: entities){
        e->save(outfile);
    }

    outfile.close();
}

//load game.  duh
void GameModel::loadGame(QString filename){
    string type;
    int id, dir, x, y;      //direction is for projectiles. will be zero for player and enemy

    ifstream infile(filename.toStdString());
    while(infile){
        infile >> type;
        infile >> id;
        if (type == "score"){
            score = id;
        }else{
            infile >> x;
            infile >> y;
            infile >> dir;
            create(type,x,y,dir);
        }
    }
    infile.close();
}

//return entity object of type specified.  returns null by default
Entity *GameModel::create(string type, int x, int y, int dir){

    if(type == "player"){
        Player* p = new Player(QPoint(x,y));
        //player = new Player(QPoint(x,y));
        entities.push_back(p);

        return p;

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

    }else if (type == "trackingprojectile"){
        QPoint tempPoint(x, y);
        TrackingProjectile* p = new TrackingProjectile(tempPoint, dir);
        entities.push_back(p);

        return p;

    }else if (type == "trackingenemy"){
        QPoint tempPoint(x,y);
        TrackingEnemy* e = new TrackingEnemy(tempPoint);
        entities.push_back(e);

        return e;

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
}
