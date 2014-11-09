#ifndef WORLDOBSERVER_H
#define WORLDOBSERVER_H

/* attempt at creating an observer interface.
 *Has methods create, move, and destroy;
 */

class WorldObserver
{
public:
    ObjectObserver();
    virtual void create() = 0;
    virtual void sendMessage() = 0;
    virtual void readMessage() = 0;
};

#endif // WORLDOBSERVER_H
