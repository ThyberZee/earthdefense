#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>
#include <sstream>  // for children classes
#include <string>
#include <QPoint>

using namespace std;

class Entity
{
protected:
    QPoint pos;
    int ID;

public:
    static int nextId;
    /* Jared -> Might it be better to use solely QPoints for everything?  opinions?
     *ie, this: */
    Entity(QPoint point);
    /* instead of this: */
    //Entity(int x, int y);

    ~Entity();

    QPoint getPos(){return pos;}
    int getId(){return ID;}

    virtual void update() = 0;
    virtual string toString() = 0;
    virtual void save(ofstream& outfile) = 0;
};

#endif // ENTITY_H
