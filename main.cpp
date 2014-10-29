#include "mainwindow.h"
#include "gamemodel.h"
#include "highscore.h"
#include <QApplication>

bool unitTest(){
    //GameModel* model = new GameModel(500,500);
    GameModel::getInstance().initializeGame();
    GameModel::getInstance().spawn(1,2,3);
    GameModel::getInstance().spawn(2,3,4);
    GameModel::getInstance().spawn(34,5,2);
    GameModel::getInstance().saveGame("savefilename");

    GameModel::getInstance().reset();

    GameModel::getInstance().loadGame("savefilename");
    GameModel::getInstance().saveGame("savefilename2");
    return true;
}

int main(int argc, char *argv[])
{
    // HighScore::getInstance()->load();



    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    unitTest();

    return a.exec();
}
