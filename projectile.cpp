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
    ss << "projectile " << pos.x() << " " << pos.y() << " " << direction;
    return ss.str();
}

void Projectile::update(){
    pos.setY(pos.y() + 10*direction);
    box->moveTo(pos.x(),pos.y());
    if(pos.y() > 800 || pos.y() < 0){   //800 screen height;
        kill();  //SEGFAULTS ABOUND!!!
    }else{
        for(Entity *entity: GameModel::getInstance().getEntities()){
            if(entity == this){
                      continue;    //prevents comparing self to self
            }else{
                QRect* otherbox = entity->getBox();
                if(box->intersects(*otherbox)){
                    this->kill();
                    entity->kill();
                }
            }
        }
    }
}

Projectile::~Projectile() { }
