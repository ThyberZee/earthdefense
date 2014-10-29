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

void Enemy::update(QPoint *newPos)
{
    pos.setX(newPos->x());
    pos.setY(newPos->y());
}
