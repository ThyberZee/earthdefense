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

void Player::load(ifstream& infile)
{
    return;
}

void Player::update(QPoint* newPos)
{
    pos.setX(newPos->x());
    pos.setY(newPos->y());
}
