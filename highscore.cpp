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
        for ( size_t i = 0; i < 10; ++i) {  // specifically, the first 10 lines
            scorefile >> line;
            scores.push_back(line);
        }
        return true;
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

    const std::string DEFAULT_CONTENTS = "10000,AAA\n9000,AAA\n8000,AAA\n7000,AAA\n6000,AAA\n5000,AAA\n4000,AAA\n3000,AAA\n2000,AAA\n1000,AAA\n";
    scorefile << DEFAULT_CONTENTS;
    scorefile.close();
}

void HighScore::write() {

}

void HighScore::addScore() {

}

HighScore::~HighScore() {}
