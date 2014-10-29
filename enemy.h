#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
private:
    int score;
public:
    Enemy(QPoint* point, int s): Entity(point), score(s) {}

    string toString();
    void save(ofstream& outfile);
    void load(ifstream& infile);
    void update(QPoint* newPos);

};

#endif // PLAYER_H
