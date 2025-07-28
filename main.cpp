#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);   //crea l'app Qt

    MainWindow w;   //la finestra
    w.show();   //mostra la finestra

    return app.exec();  //avvia il ciclo eventi Qt finché non chiudo la finestra
}
