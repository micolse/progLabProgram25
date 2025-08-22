#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>  //per scegliere i file da aggiungere
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDir>

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
    QString folderPath = QFileDialog::getExistingDirectory(   //tecnicamente aprirebbe una finestra per scegliere l'immagine
        this,   //la finestra principale
        "Seleziona la cartella",    //il titolo della fin
        "" //sarebbe la cartella (corrente, iniziale)
    );

    if (folderPath.isEmpty()) {
        QMessageBox::information(this, "nessuna cartella sel", "seleziona cartella");  //tipo se non trova l'immagine nel path, o se non ha selezionato nulla, ti avvisa
        return;
    }

    QDir dir(folderPath);
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp";
    QStringList files = dir.entryList(filters, QDir::Files);

    if (files.isEmpty()) {
        QMessageBox::information(this, "Nessun file trovato", "Non ci sono immagini nella cartella selezionata.");
        return;
    }

    for (const QString &fileName : files) {
        QString filePath = dir.filePath(fileName);

        // Divide il nome del file in titolo e autore usando "_"
        QString baseName = QFileInfo(fileName).completeBaseName(); // senza estensione
        QStringList parts = baseName.split('_');
        QString title = parts.value(0, "Titolo sconosciuto");
        QString author = parts.value(1, "Autore sconosciuto");

        playlist->addSong(filePath, title, author);
    }
}

void MainWindow::onStartClicked() {
    playlist->startTempSlide(2);    //scelto 2 sec
}

void MainWindow::onStopClicked() {
    playlist->stopTempSlide();  //ferma il timer
}
