#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>  //per scegliere i file da aggiungere
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);  //chiama il codice che crea i widget nella finestra

    playlist = new Playlist(this);

    display = new PlDisplay(this); //creo pldisplay e poi aggancio playlist, perchè farlo nel costruttore mi dava errore
    display->setPlaylist(playlist);

    display->setLabels(ui->imageLabel, ui->titleLabel, ui->authorLabel);

    connect(ui->addSongButton, &QPushButton::clicked, this, &MainWindow::onAddSongClicked);   //ho connesso i pulsanti ai metodi che li rappresentano
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopClicked);
}

MainWindow::~MainWindow() { //distruttore
    delete ui;
}

void MainWindow::onAddSongClicked() {
    QString imagePath = QFileDialog::getOpenFileName(   //tecnicamente aprirebbe una finestra per scegliere l'immagine
        this,   //la finestra principale
        "Seleziona un'immagine",    //il titolo della fin
        "", //sarebbe la cartella (corrente, iniziale)
        "Immagini (*.png *.jpg *.jpeg *.bmp)"   //filtro per far vedere solo file im
    );

    if (imagePath.isEmpty()) {
        QMessageBox::information(this, "nessuna immagine", "nessun file sel");  //tipo se non trova l'immagine nel path, o se non ha selezionato nulla, ti avvisa
        return;
    }

    bool ok;
    QString title = QInputDialog::getText(this, "Titolo della canzone", "Inserisci titolo:", QLineEdit::Normal, "", &ok);
    if (!ok || title.isEmpty()) {
        QMessageBox::information(this, "Titolo mancante", "Titolo non inserito.");
        return;
    }

    QString author = QInputDialog::getText(this, "Autore della canzone", "Inserisci l'autore:", QLineEdit::Normal, "", &ok);
    if (!ok || author.isEmpty()) {
        QMessageBox::information(this, "Autore mancante", "Autore non inserito.");
        return;
    }

    playlist->addSong(imagePath, title, author);

}

void MainWindow::onStartClicked() {
    playlist->startTempSlide(2);    //scelto 6 sec
}

void MainWindow::onStopClicked() {
    playlist->stopTempSlide();  //ferma il timer
}
