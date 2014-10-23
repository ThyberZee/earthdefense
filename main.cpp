#include "mainwindow.h"
#include <QApplication>

int main()
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
