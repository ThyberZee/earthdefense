#include "ingame.h"
#include "ui_ingame.h"
#include <QLabel>
#include <QTimer>

InGame::InGame(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::InGame)
{
    ui->setupUi(this);
}

InGame::~InGame()
{
    delete ui;
}

void InGame::keyPressEvent(QKeyEvent *ev){
    if (ev->key() == Qt::LeftArrow){ //Left key pressed
        mvPlayerTimer = new QTimer(this);
        mvPlayerTimer->setInterval(50);
        connect(mvPlayerTimer, &QTimer::timeout, this, &InGame::mvPlayerTimerHit);
        mvPlayerTimer->start();
    } else if (ev->key() == Qt::RightArrow){ //Right key pressed

    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {
    mvPlayerTimer->stop();
}

void InGame::mvPlayerTimerHit() {
    pl->update(QPoint(pl->getPos().x()-2, pl->getPos().y()));
}
