#ifndef SCORE_H
#define SCORE_H
#include <string>

class Score
{
    std::string value;
    std::string initials;

public:
// CONSTRUCTORS
    Score(std::string initValue, std::string initInitials) :
        value    (initValue),
        initials (initInitials)
    {}

// ACCESSORS
    std::string getValue()      const { return value;       }
    std::string getInitials()   const { return initials;    }

// MUTATORS
    void setValue   (std::string value)    { this->value    = value;    }
    void setInitials(std::string initials) { this->initials = initials; }

};

#endif // SCORE_H
