#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <sys/stat.h> // check if file exists (see highscore.cpp)
#include <algorithm> // std::sort
#include <vector>
    using std::vector;
#include <fstream>
    using std::ifstream;
    using std::ofstream;

#include "score.h"

///////////////////////////////////////////////


class HighScore {

private:
    vector<Score> scores;

    HighScore() { /* instantiate HighScore */ }
    ~HighScore();


public:

    // GETTERS
    Score& get(int pos); // Do we even need this?
    vector<Score>& getScores() { return scores; }


    // SETTERS


    // METHODS
    bool load();                            // load from highscore file (highscores)
    void createFile();                      // create a file that contains default high scores.
    bool fileDoesNotExist();                // check to see if there are issues with the high scores file.
    void save();                           // overwrite highscore file (highscores)
    void sort() { std::sort(scores.begin(), scores.end(), std::greater<Score>()); }
    void addScore(unsigned int newValue, std::string newInitials);
    Score newScore(unsigned int value, std::string& initials);


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
