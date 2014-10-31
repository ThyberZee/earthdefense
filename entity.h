#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>
#include <sstream>  // for children classes
#include <string>
#include <QPoint>
#include <QRect>

using namespace std;

class Entity
{
protected:
    QPoint pos;
    //QRect box;
    int ID;
    bool alive;

public:
    static int nextId;

    Entity(QPoint point);
    ~Entity();

    QPoint getPos(){return pos;}
    int getId(){return ID;}
    bool isAlive(){return alive;}

    void kill() {alive = false;}

    virtual void update() = 0;
    virtual string toString() = 0;
    virtual void save(ofstream& outfile) = 0;
};

#endif // ENTITY_H
