#include "playerwidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :QLabel(parent)
{
    player = GameModel::getInstance().getPlayer();
    //image = QPixmap(":/images/Player.png");
    setText("HEY!");

}
