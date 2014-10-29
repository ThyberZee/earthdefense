#include "entity.h"


Entity::Entity(QPoint* point) : pos(*point) {}

void Entity::load(ifstream &infile){}
void Entity::save(ofstream &outfile){}
string Entity::toString(){}
void Entity::update(QPoint* newPos){}
Entity::~Entity(){}
