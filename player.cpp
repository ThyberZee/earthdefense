#include "player.h"
#include <string>
#include <sstream>

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
void Player::update()
{
    switch(direction){
    case 0:
        break;
    case 1:
        pos.setX(pos.x() + 5);
        break;
    case -1:
        pos.setX(pos.x() - 5);
    default:
        break;
    }
}
