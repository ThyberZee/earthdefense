#include "mainwindow.h"
#include "highscore.h"
#include <QApplication>

HighScore* HighScore::instance = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
