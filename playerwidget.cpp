#include "playerwidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :QLabel(parent)
{
    player = GameModel::getInstance().getPlayer();
    image = QPixmap(":/resources/images/Player.png");


    /*setGeometry(QRect(
             player->getPos().x(),
             player->getPos().y(),
                              100,
                              100));*/
    setPixmap(image);
    setScaledContents(true);
}

PlayerWidget::~PlayerWidget() { }
