#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QVector>

class HighScore {

private:
    QVector<int> scores;

    HighScore() {
            // instantiate HighScore
    }

public:
    void loadScores()
    {
        // do something with fstream to get the scores
    }

    int getScore();

    // Methods



/***** singleton implementation ****/
private:
    static HighScore *instance;

public:
    static HighScore* getInstance() {
        if (instance == nullptr) {
            instance = new HighScore();
        }
        return instance;
    }
};



// Example usage:
    // HighScore::getInstance()->fly(3, 5);


#endif // HIGHSCORE_H
