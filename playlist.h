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
    Playlist(QObject* parent = nullptr);

    void addSong(const QString& imagePath, const QString& title, const QString& author);
    void startTempSlide(int seconds);
    void stopTempSlide();

    const Song& currentSong() const;
    int currentIndex() const;
    int getIntervalSeconds() const {
        return intervalSeconds;
    }

    void nextSong();

private:
    std::vector<Song> songs;
    int index;
    QTimer* timer;
    int intervalSeconds;
};

#endif // PLAYLIST_H
