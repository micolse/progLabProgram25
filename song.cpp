#include "song.h"

Song::Song(const QString& imagePath, const QString& title, const QString& author)
    : imagePath(imagePath), title(title), author(author) {}

QString Song::getImagePath() const {
    return imagePath;
}

QString Song::getTitle() const {
    return title;
}

QString Song::getAuthor() const {
    return author;
}
