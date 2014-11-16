#include "playerwidget.h"

PlayerWidget::PlayerWidget(Player* p, QWidget *parent) :QLabel(parent)
{
    explosionCount = 0;
    player = p;
}

PlayerWidget::~PlayerWidget() {
}
