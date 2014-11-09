#include "projectile.h"
#include "gamemodel.h"

Projectile::Projectile(QPoint p, int d): Entity(p), direction(d) {
   width  = 10;
   height = 30;
   box = new QRect(pos, QSize(10,30));
}

void Projectile::save(ofstream &outfile){
    outfile << toString() << endl;
}

string Projectile::toString(){
    stringstream ss;
    ss << "projectile " << ID << " " << pos.x() << " " << pos.y() << " " << direction;
    return ss.str();
}

void Projectile::update(){
    pos.setY(pos.y() + 10*direction);
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

Projectile::~Projectile() { }
