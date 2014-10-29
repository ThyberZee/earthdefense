#ifndef MOVEABLELABEL_H
#define MOVEABLELABEL_H

#include <QLabel>
#include <QPoint>
#include "ingame.h"
#include "ui_ingame.h"

class MoveableLabel : public QLabel {
    QWidget *win;
    QPoint offset;
    Ui::InGame* ui; // reference to the mainwindow ui
    int x;


public:
    explicit MoveableLabel(QWidget *parent, Ui::InGame *initUi);

    void keyPressEvent(QKeyEvent *ev);

    void setX(int initX) { x = initX; }

    int getX() { return x; }
};

#endif // MOVEABLELABEL_H
