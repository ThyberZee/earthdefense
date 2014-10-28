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

#include <sys/stat.h> // check if file exists (see highscore.cpp)

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;


class HighScore {

private:
    vector<std::string> scores;

    HighScore() { /* instantiate HighScore */ }


public:

    // GETTERS
    int get(int pos); // Do we even need this?


    // SETTERS


    // METHODS

    void createFile(const std::string& SCOREFILE);          // create a file that contains default high scores.
    bool fileDoesNotExist(const std::string& SCOREFILE);    // check to see if there are issues with the high scores file.
    void write();                                           // overwrite highscore file (highscores)
    bool load(const std::string& SCOREFILE);                // load from highscore file (highscores)

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

#endif // HIGHSCORE_H
