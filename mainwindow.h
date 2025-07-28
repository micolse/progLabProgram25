#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playlist.h"   //per creare la playlist
#include "plDisplay.h"  //observer concreto

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;   //classe Ui::MainWindow con tutti gli el grafici
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  //costruttore
    ~MainWindow();  //distruttore

private slots:  //cose che verranno eseguite quando clicco i bottoni GUI
    void onAddSongClicked();
    void onStartClicked();
    void onStopClicked();

private:
    Ui::MainWindow *ui; //puntatore alla GUI
    Playlist* playlist; //la playlist
    PlDisplay* display; //observer
};

#endif // MAINWINDOW_H
