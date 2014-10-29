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

void Enemy::update()
{
    pos.setX(newPos.x());
    pos.setY(newPos.y());
}
