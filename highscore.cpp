#include "highscore.h"

// If file exists, return true
bool fileExists()
{
    const std::string SCOREFILE = "scores";
    struct stat buf;

    return stat(SCOREFILE.c_str(), &buf) != 1;
}

void HighScore::createFile() {
    ofstream scorefile;
    scorefile.open("scores");
}

void HighScore::write() {

}

void HighScore::load() {
    ifstream scorefile;
    scorefile.open("scores");
}

void HighScore::addScore() {

}
