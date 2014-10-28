#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "entity.h"

class Player : public Entity
{
public:
    Player(int x, int y): Entity(x,y){}

    string toString();
    void save(ofstream& outfile);
    void load(ifstream& infile);
    void update();

};

#endif // PLAYER_H
