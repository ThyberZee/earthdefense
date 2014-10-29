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
}

InGame::~InGame()
{
    delete ui;
}

void InGame::keyPressEvent(QKeyEvent *ev){
    if (ev->key() == 0x01000012) { //Left key pressed
        mvPlayerTimer->start();
        cout << "left key pressed" << endl;
    } else if (ev->key() == 0x01000014){ //Right key pressed

    }
}

void InGame::keyReleaseEvent(QKeyEvent *ev) {
    mvPlayerTimer->stop();
}

void InGame::mvPlayerTimerHit() {
    cout << "Timer hit!" << endl;
    // MATT!!!! HELP!!!!!
}
