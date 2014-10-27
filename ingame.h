#ifndef INGAME_H
#define INGAME_H

#include <QMainWindow>

namespace Ui {
class InGame;
}

class InGame : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit InGame(QMainWindow *parent = 0);
    ~InGame();
    
private:
    Ui::InGame *ui;
};

#endif // INGAME_H
