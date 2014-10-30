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
    mvPlayerTimer = new QTimer(this);
    mvPlayerTimer->setInterval(50);
    connect(mvPlayerTimer, &QTimer::timeout, this, &InGame::mvPlayerTimerHit);

    //Josh experiment
    pl = new PlayerWidget(this);
    //pl->setPixmap(pl->getImage());

    pl->setGeometry(QRect(
             pl->getPlayer()->getPos().x(),
             pl->getPlayer()->getPos().y(),
             100, 100));
    pl->show();
    mvPlayerTimer->start();

}

InGame::~InGame()
{
    delete ui;
}

void InGame::keyPressEvent(QKeyEvent *ev){
    /*
    if (ev->key() == 0x01000012) { //Left key pressed
        mvPlayerTimer->start();
        cout << "left key pressed" << endl;
    } else if (ev->key() == 0x01000014){ //Right key pressed

    }
    */

    //JOSH EXPERIMENT
    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(-1);
    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {
    /*
    mvPlayerTimer->stop();
    */
    if (ev->key() == 0x01000012){ //left key pressed
        GameModel::getInstance().getPlayer()->setDir(0);
    }

}

void InGame::mvPlayerTimerHit() {
    /*
    cout << "Timer hit!" << endl;
    // MATT!!!! HELP!!!!!
    */

    //JOSH EXPERIEMNT
    GameModel::getInstance().update();
    pl->setGeometry(QRect(
             pl->getPlayer()->getPos().x(),
             pl->getPlayer()->getPos().y(),
             100, 100));

    pl->show();
}
