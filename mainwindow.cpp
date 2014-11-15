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
    QString initIp, netstat;
    if(ui->rbHostGame->isChecked()){
        netstat = "host";
    }else if(ui->rbJoinGame->isChecked()){
        netstat = "client";
        initIp = ui->leIP->text();
    }else{
        netstat = "single";
    }


    int initDifficulty;
    if (ui->cbDifficulty->currentIndex() == 0) {
        initDifficulty = 1;
    } else if (ui->cbDifficulty->currentIndex() == 1) {
        initDifficulty = 2;
    } else {
        initDifficulty = 3;
    }

    InGame* gameWindow = new InGame(this, "", netstat, initDifficulty, initIp);
    gameWindow->show();
    gameWindow->setEnabled(true);
    this->hide();
}

void MainWindow::on_btnLoadGame_clicked()
{
    QString netstat, initIp;

    if(ui->rbHostGame->isChecked()){
        netstat = "host";
    }else if(ui->rbJoinGame->isChecked()){
        netstat = "client";
        initIp = ui->leIP->text();
    }else{
        netstat = "single";
    }

    int initDifficulty;
    if (ui->cbDifficulty->currentIndex() == 0) {
        initDifficulty = 1;
    } else if (ui->cbDifficulty->currentIndex() == 1) {
        initDifficulty = 2;
    } else {
        initDifficulty = 3;
    }

    InGame* gameWindow = new InGame(this, "savegame", netstat, initDifficulty, initIp);
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


void MainWindow::on_rbEasy_clicked()
{

}
