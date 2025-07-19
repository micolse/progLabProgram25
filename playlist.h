#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QStringList>
#include <QTimer>
#include "subject.h"

class Playlist : public Subject {
public:
    Playlist(QObject* parent = nullptr); //sono su Qt, e richiede spesso che ogni oggetto abbia un genitore, per gestire la memoria in automatico

    void addImage(const QString& path); //add, e usa il path da cui prendere la foto
    void startTempSlide(int seconds); //inizia il timer (il timer di Qt di base lavora in millisecondi, io lo voglio in secondi perchè secondo me è piu leggibile
    void stopTempSlide(); //ferma lo slideshow

    const QString& currentImage() const; //questo è per ritornare il path all'im
    int currentIndex() const; //a che punto siamo delle immagini, tipo 1, 2..

private slots:
    void nextIm(); //ogni volta che ricomincia il timer aumenta l'index e cambia immagine (e poi chiama notify per obsv)

private:
    QStringList images;
    int index;
    QTimer* timer;
};

#endif // PLAYLIST_H
