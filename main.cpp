#include <QApplication>
#include <QDebug>
#include <QString>

#include "mainwindow.h"
#include "gamemodel.h"
#include "highscore.h"
#include "enemy.h"


bool unitTest(){
    GameModel::getInstance().initializeGame();
    GameModel::getInstance().create("enemy",1,2);
    GameModel::getInstance().create("enemy",2,3);
    GameModel::getInstance().create("enemy",34,5);
    GameModel::getInstance().saveGame("savefilename");
    qDebug(GameModel::getInstance().state().c_str());

    GameModel::getInstance().reset();

    GameModel::getInstance().loadGame("savefilename");
    GameModel::getInstance().saveGame("savefilename2");
    return true;
}

int main(int argc, char *argv[])
{
    //HighScore::getInstance()->load();
    // ^^Do not uncomment^^ -- keep the segfaults caged for now


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    unitTest();

    return a.exec();
}
