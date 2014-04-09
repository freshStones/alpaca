#include "mainwindow.h"
#include <QApplication>
#include <qunar/qunarpolicyapi.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QunarPolicyAPI qunarapi;
    qunarapi.domToFile(qunarapi.uploadPolicy());
    return a.exec();
}
