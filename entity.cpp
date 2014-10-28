#include "entity.h"


Entity::Entity(int x, int y)
{
    pos = QPoint(x,y);
}

void Entity::load(ifstream &infile){}
void Entity::save(ofstream &outfile){}
string Entity::toString(){}
void Entity::update(){}
Entity::~Entity(){}
