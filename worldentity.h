#ifndef WORLDENTITY_H
#define WORLDENTITY_H

#include <QPoint>
#include <QString>

class WorldEntity
{
    bool alive;
    QString sprite;

public:
    WorldEntity();
    bool* getAlive()     {return &alive;}
    QString* getSprite() {return &sprite;}
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
    void shoot(bool friendly);

public:
    Bullet();
};

#endif // WORLDENTITY_H
