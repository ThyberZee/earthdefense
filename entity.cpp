#include "entity.h"


Entity::Entity(QPoint* point) : pos(*point) {}


/*Don't think these are necessary...?  <- Jared */
//void Entity::load(ifstream &infile){}
//void Entity::save(ofstream &outfile){}
//string Entity::toString(){}
//void Entity::update(){}
Entity::~Entity(){}
