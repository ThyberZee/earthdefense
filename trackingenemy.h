#ifndef TRACKINGENEMY_H
#define TRACKINGENEMY_H

#include "enemy.h"

class TrackingEnemy : public Enemy
{
public:
    TrackingEnemy();
    string toString();
    void update();
};

#endif // TRACKINGENEMY_H
