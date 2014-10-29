#include <string>
#include <sstream>

#include "enemy.h"

int Enemy::score = 100;

string Enemy::toString()
{
    stringstream ss;
    ss << "enemy " << pos.x() << " " << pos.y();
    return ss.str();
}

void Enemy::save(ofstream& outfile)
{
    outfile << toString() << endl;
}

void Enemy::load(ifstream& infile)
{
    return;
}

void Enemy::update()
{
    //fix this later
    pos.setX(3);
    pos.setY(3);
}
