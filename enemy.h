#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "gamemodel.h"

class Enemy : public Entity
{
private:
    QPoint target;
    int cooldown;  //this var will countdown every frame;  when its zero, the enemy will shoot
public:
    static int score;
    Enemy(QPoint point): Entity(point), target(QPoint(rand()%500,rand()%500)), cooldown(rand()% 500) {}  //sets target to random point
    ~Enemy();

    string toString();
    void save(ofstream& outfile);
    void update();

};

#endif // PLAYER_H
