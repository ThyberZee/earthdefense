#include "player.h"

string Player::toString()
{
    stringstream ss;
    ss << "player " << pos.x() << " " << pos.y();
    return ss.str();
}

void Player::save(ofstream& outfile)
{
    outfile << toString() << endl;
}

//updates player position based on direction travelled;
void Player::   update()
{
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
