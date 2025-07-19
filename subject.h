#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <algorithm>
#include <QObject>
#include "observer.h"

class Subject : public QObject {
    Q_OBJECT
public:
    void attach(Observer* obsv) { //attach appunto serve a registrare gli obsv, cioè ad "attaccarli" nel vettore
        observers.push_back(obsv);
    }

    void detach(Observer* obsv) { //contrario di attach
        observers.erase(std::remove(observers.begin(), observers.end(), obsv), observers.end());
    }

protected:
    void notify(int currentIndex) { //viene chiamato tutte le volte che il Subject subisce un cambiamento, chiama update su tutti gli observer registrati, il currentIndex è l'indice corrente dell'immagine, da cui capiscono dove sono
        for (Observer* obsv : observers) {
            obsv->update(currentIndex);
        }
    }

private:
    std::vector<Observer*> observers; //che è una lista di puntatori a oggetti, gli oggetti implementano l'interfaccia Observer, sono quelli che vengono avvisati quando succede qualcosa
};

#endif // SUBJECT_H
