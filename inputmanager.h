#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
/////////////////////////////////////
#include <string>
#include <QDebug>



class InputManager
{
private:
    bool left, right, fire;


public:
    void keyDown(std::string key);
    void keyUp(std::string key);
    bool state(std::string key);


/***** singleton implementation ****/
private:
    static InputManager instance;

public:
    static InputManager getInstance() {
        return instance;
    }
};


#endif // INPUTMANAGER_H
