#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "entity.h"

class Player : public Entity
{
private:
    int direction; // 0 for not moving, -1 for left, and 1 for right;
public:
    Player(int x, int y): Entity(x,y){}


    string toString();
    void save(ofstream& outfile);
    void update();

};

#endif // PLAYER_H
