#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:

public:
    void save(ifstream infile);
    void load(ifstream infile);
    void update();

};

#endif // PLAYER_H
