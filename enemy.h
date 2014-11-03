#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
public:
    static int score;
    Enemy(QPoint point): Entity(point) {}
    ~Enemy();

    string toString();
    void save(ofstream& outfile);
    void update();

};

#endif // PLAYER_H
