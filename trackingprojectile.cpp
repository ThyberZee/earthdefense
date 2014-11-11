#include "trackingprojectile.h"
#include "gamemodel.h"

TrackingProjectile::TrackingProjectile(QPoint p, int d): Projectile(p,d){}

void TrackingProjectile::update(){
    if(pos.x() > GameModel::getInstance().getPlayer()->getPos().x()){
        pos.setX(pos.x() - 3);
    }else if(pos.x() < GameModel::getInstance().getPlayer()->getPos().x()){
        pos.setX(pos.x() + 3);
    }
    pos.setY(pos.y() + (GameModel::getInstance().getDifficulty()*4)*direction);
    box->moveTo(pos.x(),pos.y());
    if(pos.y() > 800 || pos.y() < 0){   //800 screen height;
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
        /*
        // kill player
        QRect* otherbox = GameModel::getInstance().getPlayer()->getBox();
        if(box->intersects(*otherbox)){
            this->kill();
            GameModel::getInstance().reset();
        }*/
    }
}
