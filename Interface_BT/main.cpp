#include <QDebug>
#include <QApplication>
#include "mainwindow.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //w.show();
    qDebug()<<"is there?"<<endl;
    return a.exec();
}
