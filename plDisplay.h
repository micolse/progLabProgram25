#ifndef PLDISPLAY_H
#define PLDISPLAY_H

#include "observer.h"
#include "playlist.h"
#include <QWidget>
#include <QLabel>


class PlDisplay : public QWidget, public Observer {
    Q_OBJECT

public:
    explicit PlDisplay(QWidget* parent = nullptr);

    void update(int currentIndex) override;
    void setPlaylist(Playlist* playlist);
    void setLabels(QLabel* image, QLabel* title, QLabel* author);

private:
    Playlist* playlistRef;

    QLabel* imageLabel;
    QLabel* titleLabel;
    QLabel* authorLabel;


};

#endif // PLDISPLAY_H
