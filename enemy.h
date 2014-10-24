#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Ship
{
    bool alive;

    // from Jared to Matt -> What is this for?
    int scoreValue;

public:
    Enemy();
};

#endif // ENEMY_H
