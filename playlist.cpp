#include "playlist.h"
#include <QTimer>
#include <QDebug>


Playlist::Playlist(QObject* parent) : Subject(), index(-1), timer(new QTimer(this)){ //index iniy a -1, crea il timer e lo connette a nextIm()
    connect(timer, &QTimer::timeout, this, &Playlist::nextSong);
    qDebug() << "Playlist creata e timer connesso ✅"; // comodi per vedere cosa sta succedendo
}

void Playlist::addSong(const QString &imagePath, const QString& title, const QString& author) { //per agg imm
    songs.emplace_back(imagePath, title, author);   //crea una song e la aggiunge
    qDebug() << "Aggiunta canzone: " << title << "di" << author;

    if (index == -1) { //se è la prima im aggiunta aggiorna subito
        index = 0;
        qDebug() << "canzone ad indice:" << index;
        notify(index);
    }
}

void Playlist::startTempSlide(int seconds) {
    timer->start(seconds * 1000);
    intervalSeconds = seconds;
}

void Playlist::stopTempSlide() {
    timer->stop();
}

void Playlist::nextSong() {
    if (songs.empty())
        return;

    index = (index +1) % songs.size(); // il % serve per il modulo perché è un loop e deve tornare all'inizio
    notify(index);
}

const Song& Playlist::currentSong() const {
    const Song& song = songs.at(index);
    return song;
}

int Playlist::currentIndex() const {
    return index;
}


