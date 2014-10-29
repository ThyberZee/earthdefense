#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
    int x; // direction: 1 for moving left, -1 for moving right
public:
    Player(QPoint point): Entity(point), x(3) {}

    string toString();
    void save(ofstream& file);
    void update(QPoint newPos);

};

#endif // PLAYER_H
