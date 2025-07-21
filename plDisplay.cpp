#include "plDisplay.h"

PlDisplay::PlDisplay(Playlist* playlist, QObject* parent) : QObject(parent), playlistRef(playlist) {
    playlistRef->attach(this); //che era fatto nell'header, ora lo aggiungerà alla lista degli observer della playlist, così potrà ricevere notifiche per ogni cambiamento

    qDebug() << "PlDisplay creato e agganciato alla Playlist come observer"; //trovo comodi i debug per capire a che punto della build sono
}

void PlDisplay::update(int currentIndex) { //qua aggiornerà la visualizzazione dell'imm cambiando la foto mostrata
    qDebug() << "ricevuto aggiornamento: indice corr:" << currentIndex;

    QString currentImg = playlistRef->currentImage();
    qDebug() << "Imm corrente:" << currentImg;
}
