#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"
#include <QPoint>

class Projectile : public Entity
{
private:
    int velocity;
public:
    Projectile(QPoint p, int v);
    string toString();
    void save(ofstream& outfile);
    void update();
};

#endif // PROJECTILE_H
