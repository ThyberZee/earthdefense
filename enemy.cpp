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
    //update x to move closer to target
    if(target.x() < pos.x()){
        pos.setX(pos.x() + 1);
    }else if(target.x() > pos.x()){
        pos.setX(pos.x() - 1);
    }

    //update y to move closer to target
    if(target.y() < pos.y()){
        pos.setY(pos.y() + 1);
    }else if(target.y() > pos.y()){
        pos.setY(pos.y() - 1);
    }
    /*
    pos.setX(rand() % 500);
    pos.setY(rand() % 500);*/
}

Enemy::~Enemy() { }
