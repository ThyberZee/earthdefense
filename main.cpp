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

<<<<<<< HEAD

    HighScore::getInstance()->load();
    HighScore::getInstance()->addScore(99999, "MSW");
    qDebug(HighScore::getInstance()->state().c_str());
    HighScore::getInstance()->reset();

    HighScore::getInstance()->load();
    qDebug(HighScore::getInstance()->state().c_str());
    HighScore::getInstance()->reset();


=======
    //GameModel::getInstance().reset();
>>>>>>> c8cef68b1addd1170e3746a40b55c337c3e13dd6
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
