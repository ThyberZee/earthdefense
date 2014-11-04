#include "entity.h"

int Entity::nextId = 0;

Entity::Entity(QPoint newPos)
{
    pos = newPos;
    justCreated = alive = true;
    ID = nextId++;
    //box = new QRect();

}

Entity::~Entity(){
    delete box; //why box has to be a pointer, I don't know
}
