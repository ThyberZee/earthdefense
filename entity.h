#ifndef ENTITY_H
#define ENTITY_H

#include <QPoint>
#include <iostream>
#include <fstream>

using namespace std;

class Entity
{
private:
    QPoint pos;

public:
    Entity(int x, int y);
    ~Entity();

    QPoint getPos(){return pos;}

    virtual void update() = 0;
    virtual void save(ifstream infile) = 0;
    virtual void load(ifstream infile) = 0;
};

#endif // ENTITY_H
