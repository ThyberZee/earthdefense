#ifndef ENEMYWIDGET_H
#define ENEMYWIDGET_H

#include "enemy.h"
#include "gamemodel.h"
#include <QLabel>

class EnemyWidget : public QLabel
{
    Q_OBJECT
private:
    //pointer to GameModel player
    Enemy* enemy;
    QPixmap image;

public:
    explicit EnemyWidget(QWidget *parent = 0);

    Enemy* getEnemy() { return enemy; }

    //getters, setters
    QPixmap getImage() { return image; }

signals:

public slots:

};

#endif // ENEMYWIDGET_H
