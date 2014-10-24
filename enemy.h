#ifndef ENEMY_H
#define ENEMY_H

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
