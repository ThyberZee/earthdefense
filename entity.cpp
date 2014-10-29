#include "entity.h"

int Entity::nextId = 0;

Entity::Entity(QPoint newPos)
{
    pos = newPos;
    ID = nextId++;

}

void Entity::save(ofstream &outfile){}
string Entity::toString(){}
void Entity::update(){}
Entity::~Entity(){}
