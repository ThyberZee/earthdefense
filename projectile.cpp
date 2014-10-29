#include "projectile.h"
#include "sstream"
#include <QPoint>

Projectile::Projectile(int x, int y, int v): Entity(QPoint(x,y)), velocity(v) {}

void Projectile::save(ofstream &outfile){
    outfile << toString() << endl;
}

string Projectile::toString(){
    stringstream ss;
    ss << "projectile " << pos.x() << " " << pos.y();
    return ss.str();
}

void Projectile::update(QPoint point){}
