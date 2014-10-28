#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity
{
public:
    Projectile(int x, int y);
    string toString();
    void save(ofstream& outfile);
    void load(ifstream& infile);
    void update();
};

#endif // PROJECTILE_H
