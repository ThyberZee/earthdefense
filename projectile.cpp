#include "projectile.h"
#include "sstream"
#include <QPoint>

Projectile::Projectile(int x, int y): Entity(x,y) {}

void Projectile::save(ofstream &outfile){
    outfile << toString() << endl;
}

string Projectile::toString(){
    stringstream ss;
    ss << "projectile " << pos.x() << " " << pos.y();
    return ss.str();
}

void Projectile::update(){}
