#include "entitywidget.h"
#include "entity.h"
#include <QLabel>
#include <QWidget>


EntityWidget::EntityWidget(QWidget *parent, Entity* init_projectile) : QLabel(parent), projectile(init_projectile)
{
    explosionCount = 0;
}

EntityWidget::~EntityWidget() {

}
