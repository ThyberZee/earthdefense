#include "highscore.h"

// If file exists, return true
bool HighScore::fileDoesNotExist(const std::string& SCOREFILE)
{
    struct stat buf;
    return stat(SCOREFILE.c_str(), &buf) != 1;
}

void HighScore::createFile(const std::string& SCOREFILE) {
    ofstream scorefile;
    scorefile.open(SCOREFILE);

    const std::string DEFAULT_CONTENTS = "10000,AAA\n9000,AAA\n8000,AAA\n7000,AAA\n6000,AAA\n5000,AAA\n4000,AAA\n3000,AAA\n2000,AAA\n1000,AAA\n";
    scorefile << DEFAULT_CONTENTS;
    scorefile.close();
}

void HighScore::write() {

}

bool HighScore::load(const std::string& SCOREFILE) {
    ifstream scorefile;
    scorefile.open(SCOREFILE);


    if (scorefile) {
        // Load the high scores (10 lines)
        std::string line;
        for ( size_t i = 0; i < 10; ++i) {
            scorefile >> line;
            scores.push_back(line);
        }
        return true;
    } else {
        return false;
    }
}

void HighScore::addScore() {

}
