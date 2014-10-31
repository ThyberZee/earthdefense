#include "ingame.h"
#include "ui_ingame.h"
#include <QLabel>
#include <QTimer>
#include <iostream>

using namespace std;

InGame::InGame(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::InGame)
{
    ui->setupUi(this);

    //start gamemodel
    GameModel::getInstance().initializeGame();
    Timer = new QTimer(this);
    Timer->setInterval(1000/30.0);
    connect(Timer, &QTimer::timeout, this, &InGame::TimerHit);

    //Josh experiment
    pl = new PlayerWidget(this);

    pl->show();
    Timer->start();

}

InGame::~InGame()
{
    delete ui;
}

void InGame::keyPressEvent(QKeyEvent *ev){
    //JOSH EXPERIMENT
    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(-1);

    }else if (ev->key() == 0x01000014){ //right key pressed
        GameModel::getInstance().getPlayer()->setDir(1);

    }else if (ev->key() == 0x20){ // space key pressed
        int x = GameModel::getInstance().getPlayer()->getPos().x();
        int y = GameModel::getInstance().getPlayer()->getPos().y();

        GameModel::getInstance().create("projectile",x,y);
    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {

    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(0);
    }else if (ev->key() == 0x01000014){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(0);
    }
}

void InGame::TimerHit() {

    GameModel::getInstance().update();
    pl->setGeometry(QRect(
             pl->getPlayer()->getPos().x(),
             pl->getPlayer()->getPos().y(),
             100, 100));
    pl->show();
    //qDebug(GameModel::getInstance().state().c_str());
}
