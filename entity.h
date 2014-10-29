#ifndef ENTITY_H
#define ENTITY_H

#include <QPoint>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Entity
{
protected:
    QPoint pos;
    int ID;

public:
    static int nextID;

    Entity(int x, int y);
    ~Entity();

    QPoint getPos(){return pos;}
    int getId(){return ID;}

    virtual void update() = 0;
    virtual string toString() = 0;
    virtual void save(ofstream& outfile) = 0;
};

#endif // ENTITY_H
