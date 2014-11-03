#include "projectile.h"

Projectile::Projectile(QPoint p, int d): Entity(p), direction(d) {}

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
    if(pos.y() > 800 || pos.y() < 0){   //800 screen height;
       // kill(); FIX SEGFAULT!!
    }
}

Projectile::~Projectile() { }
