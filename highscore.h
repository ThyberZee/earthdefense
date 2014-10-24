#ifndef HIGHSCORE_H
#define HIGHSCORE_H

class Ship {

private:
    int x, y;  // position
    int fuelLevel;  // amount of fuel
    int shields; // shield level

    Ship(int initShields) {
            // instantiate ship
    }

public:
    void fly(int direction, int distance) {
        // moves ship
    }

    void refuel(int amount) {
        // refuels ship
    }

/***** singleton implementation ****/
private:
    static Ship *instance;

public:
    static Ship* getInstance() {
        if (instance == nullptr) {
            instance = new Ship(10);
        }
        return instance;
    }

};

Ship Ship::instance = nullptr;

int main() {
    Ship::getInstance()->fly(3, 5);
}
