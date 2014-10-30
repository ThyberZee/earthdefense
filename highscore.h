#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <sys/stat.h> // check if file exists (see highscore.cpp)
#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <algorithm>
#include <QDebug>


class HighScore {

private:
    vector<std::string> scores;

    HighScore() { /* instantiate HighScore */ }
    ~HighScore();


public:

    // GETTERS
    int get(int pos); // Do we even need this?


    // SETTERS


    // METHODS
    void createFile();          // create a file that contains default high scores.
    bool fileDoesNotExist();    // check to see if there are issues with the high scores file.
    void write();               // overwrite highscore file (highscores)
    bool load();                // load from highscore file (highscores)
    void sort() { std::sort(scores.begin(), scores.end()); }
    void addScore(std::string score);


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
