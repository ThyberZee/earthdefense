#ifndef ENTITYWIDGET_H
#define ENTITYWIDGET_H

#include "entity.h"
#include <QLabel>

class EntityWidget : public QLabel
{
    Q_OBJECT
private:
    //pointer to GameModel player
    Entity* projectile;
    QPixmap image;

public:
    explicit EntityWidget(QWidget *parent = 0, Entity *init_projectile = nullptr);
    ~EntityWidget();

    Entity* getProjectile() { return projectile; }

    //getters, setters
    QPixmap getImage() { return image; }

signals:

public slots:

};

#endif // ENTITYWIDGET_H
