#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    int direction; // 0 for not moving, -1 for left, and 1 for right;
public:
    Player(QPoint point);
    ~Player();

    string toString();
    void save(ofstream& file);
    void update();

    int getDir(){return direction;}
    void setDir(int x){direction = x;}

    QPoint getPos(){return pos;}
    void setPoint(QPoint p){pos = p;}
};
#endif // PLAYER_H
