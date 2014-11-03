#include "entity.h"

int Entity::nextId = 0;

Entity::Entity(QPoint newPos)
{
    pos = newPos;
    justCreated = alive = true;
    ID = nextId++;

}

Entity::~Entity(){}
