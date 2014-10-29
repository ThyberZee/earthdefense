#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
public:
    static int score;
    Enemy(QPoint point): Entity(point) {}

    string toString();
    void save(ofstream& outfile);
    void update(QPoint newPos);

};

#endif // PLAYER_H
