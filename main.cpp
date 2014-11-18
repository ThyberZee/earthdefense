#include <QApplication>
#include <QDebug>
#include <QString>

#include "mainwindow.h"
#include "gamemodel.h"
#include "highscore.h"
#include "enemy.h"
#include "host.h"


bool unitTest(){
    GameModel::getInstance().initializeGame("single");
    GameModel::getInstance().create("enemy",100,100);
    GameModel::getInstance().create("enemy",200,200);
    GameModel::getInstance().create("enemy",300,300);
    GameModel::getInstance().create("projectile",57,801,1);
    GameModel::getInstance().saveGame("savefilename");
    qDebug() << GameModel::getInstance().state().c_str();


    // GameModel::getInstance().reset();

    GameModel::getInstance().loadGame("savefilename");
    GameModel::getInstance().saveGame("savefilename2");

    GameModel::getInstance().reset();
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    createLevels();

    if(!unitTest()) { return 1;         } // If the unit test fails, then quit;
    else            { return a.exec();  } // else, run the program.
}
