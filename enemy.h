#ifndef ENEMY_H
#define ENEMY_H


#include <string>
#include "entity.h"

class Enemy : public Entity
{
private:
    int score;
public:
    Enemy(int x, int y, int s): Entity(x,y), score(s){}

    string toString();
    void save(ofstream& outfile);
    void load(ifstream& infile);
    void update();

};

#endif // PLAYER_H
