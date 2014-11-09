#ifndef OBSERVER_H
#define OBSERVER_H

/* attempt at creating an observer interface.
 *Has methods create, move, and destroy;
 */

class ObjectObserver
{
public:
    ObjectObserver();
    virtual void create() = 0;
    virtual void destroy() = 0;
    virtual void move() = 0;
};

#endif // OBSERVER_H
