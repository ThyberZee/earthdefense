#include "ingame.h"
#include "ui_ingame.h"

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
