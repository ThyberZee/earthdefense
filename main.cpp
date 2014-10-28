#include "mainwindow.h"
#include "highscore.h"
#include <QApplication>

HighScore* HighScore::instance = nullptr; // Singleton

int main(int argc, char *argv[])
{
    if (!HighScore::getInstance()->fileExists())    // If the highscore file is not found,
    { HighScore::getInstance()->createFile(); }     // Create it.


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
