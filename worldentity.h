#ifndef WORLDENTITY_H
#define WORLDENTITY_H

#include <QPoint>
#include <QString>

class WorldEntity
{
    bool alive;
    QString sprite = "";
};

class Enemy : public WorldEntity
{               //basic enemy data
    int scorevalue;

public slots:
    void getInfo(bool* tempalive, int* tempscorevalue, QString* tempsprite);
    void create(QString type, QPoint loc);

public:
    Enemy();
};

class Player : public WorldEntity
{

};

class Bullet : public WorldEntity
{

};

#endif // WORLDENTITY_H
