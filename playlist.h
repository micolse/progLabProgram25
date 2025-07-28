#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QStringList>
#include <QTimer>
#include <vector>
#include "subject.h"
#include "song.h"

class Playlist : public Subject {
    Q_OBJECT

public:
    Playlist(QObject* parent = nullptr); //sono su Qt, e richiede spesso che ogni oggetto abbia un genitore, per gestire la memoria in automatico

    void addSong(const QString& imagePath, const QString& title, const QString& author); //add, e usa il path da cui prendere la foto, poi titolo e autore
    void startTempSlide(int seconds); //inizia il timer (il timer di Qt di base lavora in millisecondi, io lo voglio in secondi perchè secondo me è piu leggibile
    void stopTempSlide(); //ferma lo slideshow

    const Song& currentSong() const; //questo è per ritornare il path alla canzone
    int currentIndex() const; //a che punto siamo delle immagini, tipo 1, 2..

private slots:
    void nextSong(); //ogni volta che ricomincia il timer aumenta l'index e cambia canzone (e poi chiama notify per obsv)

private:
    std::vector<Song> songs;
    int index;
    QTimer* timer;
};

#endif // PLAYLIST_H
