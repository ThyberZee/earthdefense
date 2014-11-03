#ifndef PROJECTILEWIDGET_H
#define PROJECTILEWIDGET_H

#include "entity.h"
#include <QLabel>

class ProjectileWidget : public QLabel
{
    Q_OBJECT
private:
    //pointer to GameModel player
    Entity* projectile;
    QPixmap image;

public:
    explicit ProjectileWidget(QWidget *parent = 0, Entity *init_projectile = nullptr);
    ~ProjectileWidget();

    Entity* getEntity() { return projectile; }

    //getters, setters
    QPixmap getImage() { return image; }

signals:

public slots:

};

#endif // PROJECTILEWIDGET_H
