#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    int direction; // 0 for not moving, -1 for left, and 1 for right;
public:
    Player(QPoint point): Entity(point) {}

    string toString();
    void save(ofstream& file);
    void update();

};

#endif // PLAYER_H
