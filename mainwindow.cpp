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

// For when New Game and Load Game buttons are clicked
void MainWindow::startGame(QString filename) {
    QString netstat, initIp;

    if(ui->rbHostGame->isChecked()){
        netstat = "host";
    }else if(ui->rbJoinGame->isChecked()){
        netstat = "client";
        initIp = ui->leIP->text();
    }else{
        netstat = "single";
    }

    bool cheat;
    if (ui->cbCheat->isChecked()){
        cheat = true;
    } else {
        cheat = false;
    }

    int initDifficulty;
    if (ui->cbDifficulty->currentIndex() == 0) {
        initDifficulty = 1;
    } else if (ui->cbDifficulty->currentIndex() == 1) {
        initDifficulty = 2;
    } else {
        initDifficulty = 3;
    }

    InGame* gameWindow = new InGame(this, netstat, filename, initDifficulty, initIp, cheat);
    gameWindow->show();
    gameWindow->setEnabled(true);
    this->hide();
}

void MainWindow::on_btnNewGame_clicked()
{
    startGame("");
}

void MainWindow::on_btnLoadGame_clicked()
{
    startGame("savegame");
}

void MainWindow::on_btnInstructions_clicked()
{
    QMessageBox instructions;

    /*
    instructions.information(this, "Instructions", "<p style='color:orange;font-weight:bold;font-size:20px'>Use the arrow keys to move your space ship left and right," \
                             "use the space bar to shoot.  Shoot all the aliens before they invade our planet " \
                             "and destroy life as we know it.  We are all doomed if you cannot save us from " \
    */
    instructions.information(this, "Instructions", "<p style='color:orange;font-weight:bold;font-size:20px'>In a galaxy where aliens are on the verge " \
                             "of total universe domination, you and your squad are the only remaining human resistance to defend the humans on earth!<br>" \
                             "- Use the arrow keys to dodge enemy rockets, and press spacebar to combat them with your own.</p>");
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
