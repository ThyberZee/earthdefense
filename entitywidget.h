#ifndef ENTITYWIDGET_H
#define ENTITYWIDGET_H

#include "entity.h"
#include <QLabel>
#include <QWidget>

class EntityWidget : public QLabel
{
    Q_OBJECT
private:
    //pointer to GameModel player
    Entity* projectile;
    QPixmap image;
    int explosionCount;

public:
    explicit EntityWidget(QWidget *parent = 0, Entity *init_projectile = nullptr);
     ~EntityWidget();

    Entity* getEntity() { return projectile; }

    //getters, setters
    QPixmap getImage() { return image; }
    int getExpCount() { return explosionCount; }
    void incExpCount(){ explosionCount++;}

signals:

public slots:

};

#endif // ENTITYWIDGET_H
