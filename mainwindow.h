#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>

//#include "gamemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTcpServer* server;
    int connectCount;
    
private slots:


    void on_btnNewGame_clicked();
    void on_btnLoadGame_clicked();
    void on_rbSinglePlayer_clicked();
    void on_rbMultiplayer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
