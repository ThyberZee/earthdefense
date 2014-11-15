#ifndef TRACKINGENEMY_H
#define TRACKINGENEMY_H
#include "enemy.h"

class TrackingEnemy : Enemy
{
public:
    TrackingEnemy(QPoint point);
    void update();
    string toString();
};

#endif // TRACKINGENEMY_H
