#include "player.h"

Player::Player(QPoint point): Entity(point){
    width  = 100;
    height = 100;
    direction = 0;
    box = new QRect(pos, QPoint(pos.x()+width, pos.y()+width));

    //box = QRect(pos, QSize(100,100));
}

string Player::toString()
{
    stringstream ss;
    ss << "player " << ID << " " << pos.x() << " " << pos.y() << " " << 0;
    return ss.str();
}

void Player::save(ofstream& outfile)
{
    outfile << toString() << endl;
}

//updates player position based on direction travelled;
void Player::update()
{
    box->moveTo(pos.x(),pos.y());

    switch(direction){
    case 0:
        break;

    case 1: // Move Right
        if ( (pos.x() <= 640 - 100)) // game width - player width;  might want to replace with variables.
        { pos.setX(pos.x() + 5); }

        break;

    case -1: // Move Left
        if ( (pos.x() >= 0 )) {
            pos.setX(pos.x() - 5);
        }

    default:
        break;
    }
}

Player::~Player() { }
