#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <algorithm>
#include <QObject>
#include "observer.h"

class Subject : public QObject {
    Q_OBJECT
public:
    void attach(Observer* obsv) {
        observers.push_back(obsv);
    }

    void detach(Observer* obsv) {
        observers.erase(std::remove(observers.begin(), observers.end(), obsv), observers.end());
    }

protected:
    void notify(int currentIndex) {
        for (Observer* obsv : observers) {
            obsv->update(currentIndex);
        }
    }

private:
    std::vector<Observer*> observers;
};

#endif // SUBJECT_H
