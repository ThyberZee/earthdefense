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
    Enemy(QPoint point);
    ~Enemy();

    string toString();
    void save(ofstream& outfile);
    void update();
    void kill();

};

#endif // PLAYER_H
