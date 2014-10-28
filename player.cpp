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

void Player::load(ifstream& infile)
{
    return;
}

void Player::update()
{
    pos.setX(3);
    pos.setY(3);
}
