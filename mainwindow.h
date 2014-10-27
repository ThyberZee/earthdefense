#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamemodel.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>

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

    void clientConnected();
    void dataReceived();
    void clientDisconnected();

private:
    Ui::MainWindow *ui;

//private slots:
//    // slot stubs to be replaced later with real slots
//    void signal_spacebar_shoot();
//    void signal_left_arrow_moveleft();
//    void signal_right_arrow_moveright();
};

#endif // MAINWINDOW_H
