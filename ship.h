#ifndef SHIP_H
#define SHIP_H

#include <QPoint>
#include "bullet.h"


// base Ship class
class Ship
{
    Bullet bullet;

};


class Enemy : public Ship
{
    bool alive;

    // from Jared to Matt -> What is this for?
    int scoreValue;

public:
    Enemy();
};

class Player : public Ship
{
    Bullet bullet;

};

#endif // ENEMY_H
