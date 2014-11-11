#ifndef WORLDOBSERVER_H
#define WORLDOBSERVER_H

/* attempt at creating an observer interface.
 *Has methods create, move, and destroy;
 */

class WorldObserver
{
public:
    virtual void gameOver() = 0;
};

#endif // WORLDOBSERVER_H
