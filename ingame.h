#ifndef INGAME_H
#define INGAME_H

#include <QLabel>
#include <QTimer>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <iostream>
#include <typeinfo>

#include "worldobserver.h"
#include "ui_ingame.h"

#include "playerwidget.h"
#include "entitywidget.h"
#include "worldobserver.h"

#include "inputmanager.h"
#include "mainwindow.h"

namespace Ui {
class InGame;
}

class InGame : public QMainWindow, public WorldObserver
{
    Q_OBJECT
    
public:
    explicit InGame(QMainWindow *parent = 0, QString initLoadGameFile = 0, bool client = 0, int initDifficulty = 0);
    void gameOver();
    ~InGame();

private slots:

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void updateView();
    
    void on_btnSaveGame_clicked();
    void advanceLevel();

    void on_btnLoadGame_clicked();

    void on_btnStartOver_clicked();

private:
    Ui::InGame *ui;
    PlayerWidget *pl;   // Pointer to the Player Widget in model
    PlayerWidget *pl2;

    bool client;    //shows whether the game is listening for multiplayer or not

    vector<EntityWidget*> ewidgets;
    QTimer* fpsTimer;               // Timer that drives the InGame UI
    QString loadGameFile;
    int difficulty;

};

#endif // INGAME_H

