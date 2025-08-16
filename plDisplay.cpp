#include "plDisplay.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>

PlDisplay::PlDisplay(QWidget* parent) : QWidget(parent), playlistRef(nullptr) {
    imageLabel = new QLabel(this);  //inizializza QLabel
    imageLabel->setAlignment(Qt::AlignCenter);

    titleLabel = new QLabel("Titolo: ---", this);
    authorLabel = new QLabel("Autore: ---", this);

    QVBoxLayout* layout = new QVBoxLayout(this);    //layout
    layout->addWidget(imageLabel);
    layout->addWidget(titleLabel);
    layout->addWidget(authorLabel);

    setLayout(layout);

    qDebug() << "PlDisplay creato";
}

void PlDisplay::setPlaylist(Playlist* playlist) {
    playlistRef = playlist;
    if (playlistRef) {
        playlistRef->attach(this);  //attacco la playlist
        qDebug() << "pldisp agganciato";
    }
}

void PlDisplay::update(int currentIndex) { //qua aggiornerà la visualizzazione dell'imm cambiando la foto mostrata
    if (!playlistRef) {
        qDebug() << "nessuna pl" << currentIndex;
    }

    const Song& song = playlistRef->currentSong();

    //agg immagine
    QPixmap pixmap(song.getImagePath());
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio));
    } else {
        imageLabel->setText("imm non trovata");
    }

    //agg testi
    titleLabel->setText(song.getTitle());
    authorLabel->setText(song.getAuthor());

    qDebug() << "pl aggiornato con" << song.getTitle() << ", " << song.getAuthor();

}
