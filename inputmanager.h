#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#endif // INPUTMANAGER_H

#include <string>

/////////////////////////////////////

class InputManager
{
private:
    bool left, right, fire;


public:
    void keyDown(std::string key);
    void keyUp(std::string key);


/***** singleton implementation ****/
private:
    static InputManager *instance;

public:
    static InputManager* getInstance() {
        if (instance == nullptr) {
            instance = new InputManager();
        }

        return instance;
    }
};
