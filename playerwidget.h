#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include "player.h"
#include "gamemodel.h"
#include <QWidget>

class PlayerWidget : public QWidget
{
    Q_OBJECT
private:
    //pointer to GameModel player
    Player* player;
public:
    explicit PlayerWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PLAYERWIDGET_H
