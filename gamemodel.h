#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <string>
#include <vector>
#include <QWidget>

#include "entity.h"

using namespace std;

//abstract game model class
class GameModel {
private:
    vector<Entity> entities;

public:
    GameModel(QWidget* parent);
    ~GameModel();

    virtual void initializeGame();

    virtual void loadGame(string filename);

    virtual void saveGame(/*NEED TO PUT SOMETHING HERE :)*/);

};

#endif // GAMEMODEL_H
