//
// enemy.cpp
//
#include "enemy.h"

void enemy::getInfo(bool* tempalive, int* tempscorevalue, QString* tempsprite){     //Used to access enemy data
    tempalive = alive;
    tempscorevalue = scorevalue;
    tempsprite = sprite;
}

void create(QString type, QPoint loc){      //creates the enemy at set location
    if(type = "basic"){

    }
    if(type = "thief"){

    }
}
