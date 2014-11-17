#include "trackingprojectile.h"
#include "gamemodel.h"

TrackingProjectile::TrackingProjectile(QPoint p, int d): Projectile(p,d){}

void TrackingProjectile::update(){
Player* temp = GameModel::getInstance().getPlayer2();

if(temp != NULL){
    int r = rand() % 40;
    if(r <= 20){
        temp = GameModel::getInstance().getPlayer();
    }
}else{
    temp = GameModel::getInstance().getPlayer();
}

    if(pos.x() > temp->getPos().x() + 20){
        pos.setX(pos.x() - (GameModel::getInstance().getDifficulty()) * 1.5);
    }else{
        pos.setX(pos.x() + (GameModel::getInstance().getDifficulty()) * 1.5); // The horizontal movement of tproj. are determined by difficulty lvl
    }
    pos.setY(pos.y() + (GameModel::getInstance().getDifficulty()*4 /* sets speed of bullet according to difficulty level */)*direction);
    box->moveTo(pos.x(),pos.y());
    if(pos.y() > GameModel::getInstance().getWinHeight() || pos.y() < 0){
        kill();
    }else{
        for(Entity *entity: GameModel::getInstance().getEntities()){

            if(entity == this){
                 continue;    //prevents comparing self to self
            }else if (entity->toString().find("projectile") == 0){
                    continue;   //prevents comparaing to other projectiles
            }else if (entity->toString().find("enemy") == 0){

                if(direction == -1){
                    QRect* otherbox = entity->getBox();
                    if(box->intersects(*otherbox)){
                        this->kill();
                        entity->kill();
                    }
                }
            }
        }
        QRect* otherbox = GameModel::getInstance().getPlayer()->getBox();
        if(box->intersects(*otherbox) && direction == 1){
            GameModel::getInstance().gameOver();
        }
    }
}

string TrackingProjectile::toString(){
    stringstream ss;
    ss << "trackingprojectile " << ID << " " << pos.x() << " " << pos.y() << " " << direction;
    return ss.str();
}
