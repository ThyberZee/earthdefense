#include <inputmanager.h>

InputManager* InputManager::instance = nullptr;

void InputManager::keyUp(std::string key) {
         if (key == "left")  { left = true;  }
    else if (key == "right") { right = true; }
    else if (key == "fire")  { fire = true;  }
}

void InputManager::keyDown(std::string key) {
         if (key == "left")  { left = false;  }
    else if (key == "right") { right = false; }
}
