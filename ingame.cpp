#include "ingame.h"
#include "ui_ingame.h"
#include <QLabel>

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
    if (ev->key() == 0x01000012){ //Left key pressed
        QLabel* lbl = new QLabel(this);
        lbl->setText("Left key pressed.");
        lbl->setGeometry(QRect(
             rand() % (this->geometry().width() - 100),
             rand() % (this->geometry().height() - 100),
             100, 20));
        lbl->show();
    } else if (ev->key() == 0x01000014){ //Right key pressed
        QLabel* lbl = new QLabel(this);
        lbl->setText("Right key pressed.");
        lbl->setGeometry(QRect(
             rand() % (this->geometry().width() - 100),
             rand() % (this->geometry().height() - 100),
             100, 20));
        lbl->show();
    }
}
