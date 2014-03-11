#include <QCoreApplication>
#include "policyOp.h"
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QTimer>
#include <QObject>
policyOp *op;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    op = new policyOp("lhjk","lhjk","B2B_070745");

    QTimer *IDLEtimer = new QTimer;
    QObject::connect(IDLEtimer,SIGNAL(timeout()),op,SLOT(checkToStart()));
    IDLEtimer->start(1000);

    return a.exec();
}
