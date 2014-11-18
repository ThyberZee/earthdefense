#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "ingame.h"
#include "utils.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startGame(QString filename);

    QTcpServer* server;
    int connectCount;
    
public  slots:

    void on_btnNewGame_clicked();
    void on_btnLoadGame_clicked();
    void on_rbSinglePlayer_clicked();
    void on_rbMultiplayer_clicked();
    void on_btnInstructions_clicked();
    void on_rbEasy_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

