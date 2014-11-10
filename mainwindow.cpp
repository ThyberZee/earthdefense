#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnNewGame_clicked()
{
    bool isclient = ui->rbMultiplayer->isChecked();
    InGame* gameWindow = new InGame(this, "", isclient);
    gameWindow->show();
    gameWindow->setEnabled(true);
    this->hide();
}

void MainWindow::on_btnLoadGame_clicked()
{
    bool isclient = ui->rbMultiplayer->isChecked();
    InGame* gameWindow = new InGame(this, "savegame", isclient);
    gameWindow->show();
    gameWindow->setEnabled(true);
    this->hide();

}

void MainWindow::on_rbSinglePlayer_clicked()
{

}

void MainWindow::on_rbMultiplayer_clicked()
{

}

