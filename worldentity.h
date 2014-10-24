#ifndef WORLDENTITY_H
#define WORLDENTITY_H

#include <QPoint>
#include <QString>

class WorldEntity
{
    bool alive;
    QString sprite = "";

public:
    WorldEntity();
    bool getAlive(){return &alive;}
    QString getSprite(){return &sprite;}
};

class Enemy : public WorldEntity
{               //basic enemy data
    int scorevalue;

public:
    Enemy();
    int getScoreValue(){return scorevalue;}
};

class Player : public WorldEntity
{
    unsigned int score;

public:
    Player();
    unsigned int getScore(){return score;}
};

class Bullet : public WorldEntity
{

public:
    Bullet();
};

#endif // WORLDENTITY_H
