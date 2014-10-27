/*
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
    // Getters & Setters
    int getScore();

    // Methods
    void loadScores()
    {

    }
*/


/***** singleton implementation ****/
/*
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
*/


#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDebug>

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;



class HighScore {

private:
    vector<string> scores;

    HighScore() { /* instantiate HighScore */ }

public:

    int get(int pos);

    void write();   // overwrite highscore file (highscores)
    void load();    // load from highscore file (highscores)
    void addScore();



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
