#include "projectile.h"
#include "sstream"
#include <QPoint>

Projectile::Projectile(QPoint p, int v): Entity(p), velocity(v) {}

void Projectile::save(ofstream &outfile){
    outfile << toString() << endl;
}

string Projectile::toString(){
    stringstream ss;
    ss << "projectile " << pos.x() << " " << pos.y();
    return ss.str();
}

void Projectile::update(){
    //do stuff
}
