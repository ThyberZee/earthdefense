#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>
#include <highscore.h>
#include <QLabel>
#include <QGridLayout>
#include <QLayoutItem>
#include <QLineEdit>
#include <mainwindow.h>

namespace Ui {
class Gameover;
}

class Gameover : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Gameover(QWidget *parent = 0, int score = 0);
    ~Gameover();
    
private:
    Ui::Gameover *ui;
    int score;


private slots:
    void on_lineEdit_returnPressed();
};

#endif // GAMEOVER_H
