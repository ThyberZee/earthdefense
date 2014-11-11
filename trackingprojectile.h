#ifndef TRACKINGPROJECTILE_H
#define TRACKINGPROJECTILE_H

#include "projectile.h"
#include <QPoint>

class TrackingProjectile : public Projectile
{
public:
    TrackingProjectile(QPoint p, int d);
    string toString();
    void update();
};

#endif // TRACKINGPROJECTILE_H
