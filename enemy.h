#ifndef ENEMY_H
#define ENEMY_H

#ifndef "gamemodel.h"
#define "gamemodel.h"
#endif

#include <QPoint>


class Enemy : public Ship
{
private:
    bool alive = true;
    int scoreValue;

public:
    Enemy();
};

#endif // ENEMY_H
