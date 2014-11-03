#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "sstream"
#include "entity.h"
#include <QPoint>

class Projectile : public Entity
{
private:
    int direction;
public:
    Projectile(QPoint p, int v);
    ~Projectile();
    string toString();
    void save(ofstream& outfile);
    void update();
};

#endif // PROJECTILE_H
