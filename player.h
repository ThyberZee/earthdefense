#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
    int x;
public:
    Player(QPoint* point): Entity(point), x(3) {}

    string toString();
    void save(ofstream& file);
    void load(ifstream& infile);
    void update(QPoint *newPos);

};

#endif // PLAYER_H
