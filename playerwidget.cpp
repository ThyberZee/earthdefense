#include "playerwidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :QLabel(parent)
{
    player = GameModel::getInstance().getPlayer();
    image = QPixmap(":/resources/images/Player.png");
    setPixmap(image);
    setScaledContents(true);
}

PlayerWidget::~PlayerWidget() { }
