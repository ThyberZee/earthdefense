#include "highscore.h"


HighScore* HighScore::instance = nullptr;

// called sometime before it is needed
bool HighScore::load() {
    if (fileDoesNotExist())   // If the highscore file is not found,
    {   createFile();     }   // Create it.

    ifstream scorefile;               // load the "scores" file
    scorefile.open("scores");

    if (scorefile) {                        // If the scores file loaded without having issues
        std::string line;                   // Load the contents into a vector<string>
        for ( size_t i = 0; i < 5; ++i) {   // specifically, the first 10 lines
            scorefile >> line;
            scores.push_back(line);
        }

        sort();                             // then sort in the correct order
        return true;                        // aaand... done!
    } else {
        return false;
    }
}

// If file exists, return true
bool HighScore::fileDoesNotExist()
{
    const std::string SCOREFILE = "scores";
    struct stat buf;
    return stat(SCOREFILE.c_str(), &buf) != 1;
}

// Creates a file containing default high scores
void HighScore::createFile() {
    ofstream scorefile;
    scorefile.open("scores");

    const std::string DEFAULT_CONTENTS = "10000,AAA\n8000,AAA\n6000,AAA\n4000,AAA\n2000,AAA";
    scorefile << DEFAULT_CONTENTS;
    scorefile.close();
}

void HighScore::write() {
    ofstream scorefile;
    scorefile.open("scores");
    for (size_t i = 0; i < 5; ++i) {
        scorefile << scores.at(i) << "\n";
    }
    scorefile.close();
}

void HighScore::addScore(std::string score) {
    scores.push_back(score);
    HighScore::sort();
    scores.pop_back();
    HighScore::write();
}

HighScore::~HighScore() {}
