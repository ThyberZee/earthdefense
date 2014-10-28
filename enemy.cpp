#include <string>
#include <sstream>

#include "enemy.h"


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
    pos.setX(3);
    pos.setY(3);
}
