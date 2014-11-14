#include <inputmanager.h>

InputManager InputManager::instance;

void InputManager::keyDown(std::string key) {
         if (key == "left")  { left = true;  }
    else if (key == "right") { right = true; }
    else if (key == "fire")  { fire = true;  }
         qDebug() << "keydown: " << QString::fromStdString(key);

}
void InputManager::keyUp(std::string key) {
         if (key == "left")  { left = false;  }
    else if (key == "right") { right = false; }
         else if (key == "fire") { right = false;}

         qDebug() << "keyup: " << QString::fromStdString(key);
}

bool InputManager::state(std::string key){
         if (key == "left") { return left; }
    else if (key == "right") { return right; }
    else if (key == "fire") { return fire; }
}
