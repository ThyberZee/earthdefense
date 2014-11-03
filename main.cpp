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


    HighScore::getInstance()->load();
    HighScore::getInstance()->addScore(99999, "MSW");
    qDebug(HighScore::getInstance()->state().c_str());
    HighScore::getInstance()->reset();

    HighScore::getInstance()->load();
    qDebug(HighScore::getInstance()->state().c_str());
    HighScore::getInstance()->reset();


    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if(!unitTest()) { return 0;         } // If the unit test fails, then quit;
    else            { return a.exec();  } // else, run the program.
}
