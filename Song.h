#ifndef SONG_H
#define SONG_H

#include <QString>

class Song {
public:
    Song(const QString& imagePath, const QString& title, const QString& author);

    QString getImagePath() const;
    QString getTitle() const;
    QString getAuthor() const;

private:
    QString imagePath;
    QString title;
    QString author;
};

#endif // SONG_H
