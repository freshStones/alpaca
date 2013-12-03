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
    op->GetAllCommonPolicy("0","0");
    QTimer *timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),op,SLOT(alter()));
    timer->start(3000);
    return a.exec();
}
