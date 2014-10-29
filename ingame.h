#ifndef INGAME_H
#define INGAME_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include "playerwidget.h"

#include "player.h"

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
    void keyReleaseEvent(QKeyEvent *);
    void mvPlayerTimerHit();
    
private:
    Ui::InGame *ui;
    PlayerWidget *pl;  // Pointer to the Player Object
    QTimer *mvPlayerTimer;

};

#endif // INGAME_H
