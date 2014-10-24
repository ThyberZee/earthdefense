#ifndef SHIP_H
#define SHIP_H

#include <QPoint>
#include "bullet.h"


// base Ship class
class Ship
{
    Bullet bullet;

};

class Player : public Ship
{
    Bullet bullet;

};

#endif // ENEMY_H
