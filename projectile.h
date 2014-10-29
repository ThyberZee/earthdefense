#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity
{
private:
    int velocity;
public:
    Projectile(int x, int y, int v);
    string toString();
    void save(ofstream& outfile);
    void update(QPoint point);
};

#endif // PROJECTILE_H
