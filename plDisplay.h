#ifndef PLDISPLAY_H
#define PLDISPLAY_H

#include "observer.h"
#include "playlist.h"
#include <QWidget>
#include <QLabel>


class PlDisplay : public QWidget, public Observer {
    Q_OBJECT

public:
    explicit PlDisplay(QWidget* parent = nullptr); //qui effettivamente vediamo l'uso dell'observer concreto: "osserva" la Playlist*

    void update(int currentIndex) override; //il punto di pldisplay: implementare il cambiamento della canzone ogni volta che vede in playlist che è cambiata
    void setPlaylist(Playlist* playlist);

private:
    Playlist* playlistRef; //è il puntatore alla playlist che l'observer concreto sta "osservando"

    QLabel* imageLabel;
    QLabel* titleLabel;
    QLabel* authorLabel;


};

#endif // PLDISPLAY_H
