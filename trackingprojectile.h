#ifndef TRACKINGPROJECTILE_H
#define TRACKINGPROJECTILE_H

#include "projectile.h"
#include <QPoint>

class TrackingProjectile : public Projectile
{
public:
    TrackingProjectile(QPoint p, int d);
    void update();
};

#endif // TRACKINGPROJECTILE_H
