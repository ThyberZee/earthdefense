#include "entity.h"

int Entity::nextID = 0;

Entity::Entity(int x, int y)
{
    pos = QPoint(x,y);
    ID = nextID++;

}

void Entity::load(ifstream &infile){}
void Entity::save(ofstream &outfile){}
string Entity::toString(){}
void Entity::update(){}
Entity::~Entity(){}
