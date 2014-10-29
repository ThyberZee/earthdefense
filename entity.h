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

public:
    /* Jared -> Might it be better to use solely QPoints for everything?  opinions?
     *ie, this: */
    Entity(QPoint* point);
    /* instead of this: */
    //Entity(int x, int y);
    ~Entity();

    QPoint getPos(){return pos;}

    /* Jared -> no need for pure virtual functions.  Pure virtual functions make
     *a class abstract...you cannot instantiate it.  When we make an entity,
     *we give it a QPoint as a <pos>, that's instantiating the object. So
     *pure virtual functions would not work here.  ...just thinking out loud.
     *What do you guys think? */
    virtual void update();
    virtual string toString();
    virtual void save(ofstream& outfile);
    virtual void load(ifstream& infile);
};

#endif // ENTITY_H
