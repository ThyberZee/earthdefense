#include "highscore.h"

/////////////////////////////////////////

HighScore* HighScore::instance = nullptr;

// called sometime before it is needed
bool HighScore::load() {
    if (fileDoesNotExist())   // If the highscore file is not found,
    {   createDefault();     }   // Create it.

    ifstream scorefile;               // load the "scores" file
    scorefile.open("scores");

    if (scorefile) {                        // If the scores file loaded without having issues, do the following
        for ( size_t i = 0; i < 5; ++i) {   // Load 5 scores into a vector<Score*>
            unsigned int value;     scorefile >> value;
            std::string initials;   scorefile >> initials;
            addScore(value, initials);      // and add it to the vector of scores
        }

        scorefile.close();                  // Close the file
        return true;                        // aaand... done!
    } else {
        return false;
    }
}

// Not sure why this even is here...
/*Score HighScore::newScore(unsigned int value, std::string& initials) {
    Score score(value, initials);
    return score;
}*/

// If file exists, return true
bool HighScore::fileDoesNotExist()
{
    const std::string SCOREFILE = "scores";
    struct stat buf;
    return stat(SCOREFILE.c_str(), &buf) != 1;
}

// Creates a file containing default high scores ONLY WHEN THE FILE DOES NOT EXIST
void HighScore::createDefault() {
    ofstream scorefile;
    scorefile.open("scores");

    const std::string DEFAULT_CONTENTS = "10000 AAA\n8000 AAA\n6000 AAA\n4000 AAA\n2000 AAA";
    scorefile << DEFAULT_CONTENTS;
    scorefile.close();
}


void HighScore::save() {
    ofstream scorefile;
    scorefile.open("scores");

    for (size_t i = 0; i < 5; ++i) {
        Score& s = scores.at(i);
        scorefile << s.toString() << "\n";
    }
    scorefile.close();
}

// Add score to the vector of scores, then sort in order,
// take the lowest score (last in vector) out, and save the new highscores file 'scores'
void HighScore::addScore(unsigned int newValue, std::string newInitials) {
    Score s(newValue, newInitials);
    scores.push_back(s);
    HighScore::sort();
    if (scores.size() > 5) {
        scores.pop_back();
        save();
    }

}

std::string HighScore::state() {
    std::stringstream ss;

    ifstream scorefile;                     // load the "scores" file
    scorefile.open("scores");

    for (size_t i = 0; i < scores.size(); ++i)
    {
        Score& s = scores.at(i);
        ss << s.toString() << "\n";
    }

    return ss.str();
}

HighScore::~HighScore() {

}
