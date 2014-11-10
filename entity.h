#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>
#include <sstream>  // for children classes
#include <string>
#include <QPoint>
#include <QRect>
#include <QSize>

using namespace std;

class Entity
{
protected:
    QPoint pos;
    QRect* box;     //making this a pointer removes weird errors  dont know why

    int ID;
    // width and height waz heer
    bool alive, justCreated;

public:
    static int nextId;
    int width, height;

    Entity(QPoint point);
    ~Entity();

    QPoint getPos(){return pos;}
    void setPos(QPoint p) {pos = p;}
    int getId(){return ID;}
    void setId(int id){ID = id;}  //use sparingly
    bool isAlive(){return alive;}
    bool getJustCreated(){return justCreated;}
    void setJustCreated(bool b){justCreated = b;}

    QRect* getBox(){return box;}

    virtual void kill() {alive = false;}
    virtual void update() = 0;
    virtual string toString() = 0;
    virtual void save(ofstream& outfile) = 0;
};

#endif // ENTITY_H
