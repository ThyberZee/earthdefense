#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
protected:
    QPoint target;
    int cooldown;  //this var will countdown every frame;  when its zero, the enemy will shoot
public:
    static int score;
    Enemy(QPoint point);
    ~Enemy();

    string toString();
    void save(ofstream& outfile);
    void update();
    void kill();

};

#endif // ENEMY_H
