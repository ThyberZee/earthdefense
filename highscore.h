#ifndef HIGHSCORE_H
#define HIGHSCORE_H

class HighScore {

private:
    int x, y;  // position
    int fuelLevel;  // amount of fuel
    int shields; // shield level

    HighScore(int initShields) {
            // instantiate HighScore
    }

public:
    void fly(int direction, int distance) {
        // moves HighScore
    }

    void refuel(int amount) {
        // refuels HighScore
    }

/***** singleton implementation ****/
private:
    static HighScore *instance;

public:
    static HighScore* getInstance() {
        if (instance == nullptr) {
            instance = new HighScore(10);
        }
        return instance;
    }

};



// Example usage:
    // HighScore::getInstance()->fly(3, 5);


#endif // HIGHSCORE_H
