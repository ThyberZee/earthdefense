#ifndef ENEMY_H
#define ENEMY_H

#include <QString>
#include <QPoint>

class Enemy
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

#endif // ENEMY_H
