#include "player.h"

Player::Player(QPoint point): Entity(point){
    width  = 50;
    height = 50;
    direction = 0;
    box = new QRect(pos, QPoint(pos.x()+width, pos.y()+width));
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
        if ( (pos.x() <= 640 - 50)) // game width - player width;  might want to replace with variables.
        { pos.setX(pos.x() + 5); }  // would have a file of ONLY constants where we define all these things...but no time now :)

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
