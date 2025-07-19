#include "playlist.h"
#include <QTimer>
#include <QDebug>

void logPlaylist(const QString& msg) {
    qDebug() << "[🎞️ Playlist]" << msg;
}

Playlist::Playlist(QObject* parent) : Subject(), index(-1), timer(new QTimer(this)){ //index iniy a -1, crea il timer e lo connette a nextIm()
    connect(timer, &QTimer::timeout, this, &Playlist::nextIm);
    logPlaylist("Playlist creata e timer connesso ✅"); // comodi per vedere cosa sta succedendo
}

void Playlist::addImage(const QString &imagePath) { //per agg imm
    images.push_back(imagePath);
    logPlaylist("Aggiunta immagine: " + imagePath + " 📷");

    if (index == -1) { //se è la prima im aggiunta aggiorna subito
        index = 0;
        logPlaylist("Immagine corrente impostata a indice 0 🎬");
        notify(index);
    }
}

void Playlist::startTempSlide(int seconds) {
    int intervalMs = seconds * 1000; //ecco quello che mancava dall'header, dove io metto i secondi, e qua li trasforma in millisec perché è quello con cui lavora QTimer
    timer->start(intervalMs); //Ms=millisec
    logPlaylist("Timer avviato con intervallo di " + QString::number(intervalMs) + " ms ⏱️");
}

void Playlist::stopTempSlide() {
    timer->stop();
    logPlaylist("slide stop ⏹️");
}

void Playlist::nextIm() {
    if (images.empty())
        logPlaylist("Nessuna immagine nella playlist ❌");
        return;

    index = (index +1) % images.size(); // il % serve per il modulo perché è un loop e deve tornare all'inizio
    logPlaylist("prossima immagine, numero: " + QString::number(index) + " ➡️");
    notify(index);
}

const QString& Playlist::currentImage() const {
    logPlaylist("immagine adesso: " + (images.empty() ? "nessuna" : images[index]) + " 🎞️");
    return images[index];
}

int Playlist::currentIndex() const {
    logPlaylist("Indice adesso: " + QString::number(index) + " 🔢");
    return index;
}


