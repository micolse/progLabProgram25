#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "playlist.h"
#include "plDisplay.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddSongClicked();
    void onStartClicked();
    void onStopClicked();

private:
    Ui::MainWindow *ui;
    Playlist* playlist;
    PlDisplay* display;
};

#endif // MAINWINDOW_H
