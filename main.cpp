#include "mainwindow.h"
#include "highscore.h"
#include <QApplication>

HighScore* HighScore::instance = nullptr; // Singleton

int main(int argc, char *argv[])
{
// Stuff to do before the main window pops up
    /**** HighScore Stuff ****/
    if (HighScore::getInstance()->fileDoesNotExist("scores"))   // If the highscore file is not found,
    {   HighScore::getInstance()->createFile("scores"); }       // Create it.

    HighScore::getInstance()->load("scores");
    /****                 ****/

    /**** Your stuff here ****/
    /****                 ****/




// A wild MainWindow appears!
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
