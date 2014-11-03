#include "enemy.h"

int Enemy::score = 100;

string Enemy::toString()
{
    stringstream ss;
    ss << "enemy " << pos.x() << " " << pos.y() << " " << 0;
    return ss.str();
}

void Enemy::save(ofstream& outfile)
{
    outfile << toString() << endl;
}

void Enemy::update()
{
    if(QPoint(pos.x(),pos.y()) == target){
        target = QPoint(rand( )% 500,rand( )% 500);     //if current position equals target, create new random target
    }else{
        //update x to move closer to target
        if(target.x() < pos.x()){
            pos.setX(pos.x() - 1);
        }else if(target.x() > pos.x()){
            pos.setX(pos.x() + 1);
        }

        //update y to move closer to target
        if(target.y() < pos.y()){
            pos.setY(pos.y() - 1);
        }else if(target.y() > pos.y()){
            pos.setY(pos.y() + 1);
        }
    }

    //decrement cooldown; if 0, shoot and reset to random val;
    if(--cooldown == 0){
        GameModel::getInstance().create("projectile",pos.x(),pos.y(),1);
        cooldown = rand() % 1000;
    }
}

Enemy::~Enemy() { }
