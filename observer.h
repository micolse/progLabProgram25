#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(int currentIndex) = 0; //praticamente ogni volta che la playlist cambia "canzone" viene chiamato, perchè updata le immagini
};

#endif // OBSERVER_H
