#include "entity.h"
#include "projectilewidget.h"

ProjectileWidget::ProjectileWidget(QWidget *parent, Entity* init_projectile) : QLabel(parent), projectile(init_projectile)
{
}

ProjectileWidget::~ProjectileWidget() {

}
