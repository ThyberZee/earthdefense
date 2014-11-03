#ifndef INGAME_H
#define INGAME_H

#include <QLabel>
#include <QTimer>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <iostream>
#include <typeinfo>
#include "ui_ingame.h"
#include "playerwidget.h"

#include "enemywidget.h"
#include "projectilewidget.h"

namespace Ui {
class InGame;
}

class InGame : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit InGame(QMainWindow *parent = 0);
    ~InGame();

private slots:

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void updateView();
    
private:
    Ui::InGame *ui;
    PlayerWidget *pl;               // Pointer to the Player Widget in model
    vector<ProjectileWidget*> pr;   // Pointer to the vector of Projectile Widgets, which contain pointers to the underlying objects in the model
    vector<EnemyWidget*> en;        // Pointer to the vector of Enemy Widgets       '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    QTimer *fpsTimer;               // Timer that drives the InGame UI

};

#endif // INGAME_H
