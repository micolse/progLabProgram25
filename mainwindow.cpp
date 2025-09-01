#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    playlist = new Playlist(this);

    display = new PlDisplay(this); //creo pldisplay e poi aggancio playlist, perchè farlo nel costruttore mi dava errore
    display->setPlaylist(playlist);

    display->setLabels(ui->imageLabel, ui->titleLabel, ui->authorLabel);

    connect(ui->addSongButton, &QPushButton::clicked, this, &MainWindow::onAddSongClicked);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onAddSongClicked() {
    QString folderPath = QFileDialog::getExistingDirectory(
        this,
        "Seleziona la cartella",
        ""
    );

    if (folderPath.isEmpty()) {
        QMessageBox::information(this, "nessuna cartella sel", "seleziona cartella");
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

        QString baseName = QFileInfo(fileName).completeBaseName();
        QStringList parts = baseName.split('_');
        QString title = parts.value(0, "Titolo sconosciuto");
        QString author = parts.value(1, "Autore sconosciuto");

        playlist->addSong(filePath, title, author);
    }
}

void MainWindow::onStartClicked() {
    playlist->startTempSlide(3);
}

void MainWindow::onStopClicked() {
    playlist->stopTempSlide();
}
