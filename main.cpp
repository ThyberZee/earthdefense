#include "mainwindow.h"
#include "gamemodel.h"
#include <QApplication>

bool unitTest(){
    GameModel* model = new GameModel();
    model->spawn(1,2,3);
    model->spawn(2,3,4);
    model->spawn(34,5,2);
    model->saveGame("savefilename");

    model->reset();

    model->loadGame("savefilename");
    model->saveGame("savefilename2");
    return true;

}

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    unitTest();

    return a.exec();
}
