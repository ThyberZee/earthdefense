#ifndef ENEMY_H
#define ENEMY_H


#include <string>
#include "entity.h"

class Enemy : public Entity
{
public:
    static int score;
    Enemy(int x, int y): Entity(x,y){}

    string toString();
    void save(ofstream& outfile);
    void update();

};

#endif // PLAYER_H
