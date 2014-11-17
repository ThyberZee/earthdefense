#ifndef INGAME_H
#define INGAME_H

#include <QLabel>
#include <QTimer>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QString>
#include <iostream>
#include <typeinfo>

#include "worldobserver.h"
#include "ui_ingame.h"

#include "playerwidget.h"
#include "entitywidget.h"
#include "worldobserver.h"

#include "inputmanager.h"
#include "mainwindow.h"
#include "highscore.h"

namespace Ui {
class InGame;
}

class InGame : public QMainWindow, public WorldObserver
{
    Q_OBJECT
    
public:
    explicit InGame(QMainWindow *parent = 0, QString netstat = 0, QString filename = 0, int initDifficulty = 0, QString initIp = 0);
    void gameOver();
    ~InGame();

private slots:

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void updateView();
    
    void on_btnSaveGame_clicked();
    void advanceLevel();

    void on_btnStartOver_clicked();

private:
    Ui::InGame *ui;
    PlayerWidget *pl;   // Pointer to the Player Widget in model
    PlayerWidget *pl2;  // Pointer to other player.  only used if multiplayer;

    bool client;    //shows whether the game is listening for multiplayer or not
    QString netstatus;   //shows whether game is singleplayer, hosting, or listening.

    vector<EntityWidget*> ewidgets;
    QTimer* fpsTimer;               // Timer that drives the InGame UI
    QString loadGameFile, ip;
    int difficulty;

};

#endif // INGAME_H

