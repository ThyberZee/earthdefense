#include "entitywidget.h"

EntityWidget::EntityWidget(QWidget *parent, Entity* init_projectile) : QLabel(parent), projectile(init_projectile)
{
    explosionCount = 0; // For the explosion animation
}

EntityWidget::~EntityWidget() {

}
