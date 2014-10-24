#ifndef WORLDENTITY_H
#define WORLDENTITY_H

#include <QPoint>
#include <QString>

class WorldEntity
{

};

class Enemy : public WorldEntity
{               //basic enemy data
    bool alive;
    int scorevalue;
    QString sprite = "";

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
