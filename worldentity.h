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
    bool getAlive() const       {return &alive;}
    QString getSprite() const   {return &sprite;}
};

class Enemy : public WorldEntity
{               //basic enemy data
public:
    Enemy();
    int getScoreValue() const {return 200;}
};

class Player : public WorldEntity
{
    unsigned int score;

public:
    Player();
    unsigned int getScore() const {return score;}
};

class Bullet : public WorldEntity
{

public:
    Bullet();
};

#endif // WORLDENTITY_H
