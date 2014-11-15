#include "playerwidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :QLabel(parent)
{
    explosionCount = 0;
    player = GameModel::getInstance().getPlayer();
    image = QPixmap(":/resources/images/Player.png");
    setPixmap(image);
    setScaledContents(true);
}

PlayerWidget::~PlayerWidget() {
}
