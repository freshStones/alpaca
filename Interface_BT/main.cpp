#include <QDebug>
#include <QApplication>
#include <QCleanlooksStyle>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle(new QCleanlooksStyle());

    MainWindow w;
    w.show();
    
    return a.exec();
}
