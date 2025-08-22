#include "plDisplay.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QPainter>
#include <QPainterPath>

PlDisplay::PlDisplay(QWidget* parent) : QWidget(parent), playlistRef(nullptr), imageLabel(nullptr), titleLabel(nullptr), authorLabel(nullptr) {
    qDebug() << "PlDisplay creato";
}

void PlDisplay::setPlaylist(Playlist* playlist) {
    playlistRef = playlist;
    if (playlistRef) {
        playlistRef->attach(this);  //attacco la playlist
        qDebug() << "pldisp agganciato";
    }
}

void PlDisplay::setLabels(QLabel* image, QLabel* title, QLabel* author) {
    imageLabel = image;
    titleLabel = title;
    authorLabel = author;
}

void PlDisplay::update(int currentIndex) { //qua aggiornerà la visualizzazione dell'imm cambiando la foto mostrata
    if (!playlistRef || !imageLabel || !titleLabel || !authorLabel) {
        qDebug() << "pl non inizializzata correttamente";
        return;
    }

    const Song& song = playlistRef->currentSong();

    QPixmap orig(song.getImagePath());
    if (!orig.isNull()) {
        QPixmap scaled = orig.scaled(380, 330, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        QPixmap rounded(380, 330);
        rounded.fill(Qt::transparent);

        QPainter painter(&rounded);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(0, 0, 380, 330, 20, 20);
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, scaled);

        QPen pen(Qt::black, 2);
        painter.setPen(pen);
        painter.drawRoundedRect(0, 0, 380, 330, 20, 20);

        painter.end();

        imageLabel->setPixmap(rounded);
    } else {
        imageLabel->setText("imm non trovata");
    }


    //agg testi
    titleLabel->setText(QString("- %1 -").arg(song.getTitle()));
    authorLabel->setText(QString("- %1 -").arg(song.getAuthor()));

    qDebug() << "pl aggiornato con" << song.getTitle() << ", " << song.getAuthor();

}
