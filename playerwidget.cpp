#include "playerwidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :
    QWidget(parent)
{
    player = GameModel::getInstance().getPlayer();
}
