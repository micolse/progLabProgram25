#ifndef PLDISPLAY_H
#define PLDISPLAY_H

#include "observer.h"
#include "playlist.h"
#include <QObject>
#include <QDebug>

class PlDisplay : public QObject, public Observer {
    Q_OBJECT

public:
    PlDisplay(Playlist* playlist, QObject* parent = nullptr); //qui effettivamente vediamo l'uso dell'observer concreto: "osserva" la Playlist*
    // QObject* parent serve a gestire la memoria in modo automatico nella GUI

    void update(int currentIndex) override; //il punto di pldisplay: implementare il cambiamento della canzone ogni volta che vede in playlist che è cambiata

private:
    Playlist* playlistRef; //è il puntatore alla playlist che l'observer concreto sta "osservando"

    /*poi, in pratica, mi servirà nel .cpp, perché quando vedrà che è cambiata la canzone,
    e dovrà spostarsi all'indice X, non avrà l'immagine associata, per questo ho bisogno di un puntatore alla
    playlist, così potrà usare currentImage o currentIndex e cambiare effettivamente indice e immagine.*/


};

#endif // PLDISPLAY_H
