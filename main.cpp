#include <QApplication>
#include <QDebug>
#include <QString>

#include "mainwindow.h"
#include "gamemodel.h"
#include "highscore.h"
#include "enemy.h"


bool unitTest(){
    GameModel::getInstance().initializeGame();
    GameModel::getInstance().create("enemy",100,100);
    GameModel::getInstance().create("enemy",200,200);
    GameModel::getInstance().create("enemy",300,300);
    GameModel::getInstance().saveGame("savefilename");
    qDebug(GameModel::getInstance().state().c_str());

    GameModel::getInstance().reset();

    GameModel::getInstance().loadGame("savefilename");
    GameModel::getInstance().saveGame("savefilename2");

    //GameModel::getInstance().reset();
    return true;
}

int main(int argc, char *argv[])
{
    HighScore::getInstance()->load();
    HighScore::getInstance()->addScore(99999999999999999, "MSW");


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    unitTest();

    return a.exec();
}
