#include "ingame.h"
#include "ui_ingame.h"
#include <QLabel>
#include <QTimer>

InGame::InGame(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::InGame),
    pl(new PlayerWidget(this))
{
    ui->setupUi(this);
    mvPlayerTimer = new QTimer(this);
    mvPlayerTimer->setInterval(50);
    connect(mvPlayerTimer, &QTimer::timeout, this, &InGame::mvPlayerTimerHit);
}

InGame::~InGame()
{
    delete ui;
}

void InGame::keyPressEvent(QKeyEvent *ev){
    if (ev->key() == Qt::LeftArrow){ //Left key pressed
        mvPlayerTimer->start();
    } else if (ev->key() == Qt::RightArrow){ //Right key pressed

    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {
    mvPlayerTimer->stop();
}

void InGame::mvPlayerTimerHit() {
    pl->getPlayer()->update();
    pl->setGeometry(0,0, 111, 111);
    pl->show();
}
