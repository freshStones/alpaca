#ifndef DUMP_H
#define DUMP_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QDebug>
#include <btDatabase.h>
#include <QString>
#include <qfile.h>
//#include <QAxObject>
#include <QFileDialog>
#include <QObject>
#include <QVector>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QFileDialog>
#include <QVector>




class dump{

public:

    void init();
    QVector<QStringList> dumpFromB2Q(QSqlTableModel *model,QString moneyKeep,QString memo,QString latestPreticketTimeLimit,QString policyCode,QString canPayDirectly,QString pnr,QString pat,QString suppierCode,QString isItinerarySupplied,QString dep,QString arv,QVector<QString> space);
    void save();
    //void saveAsExcel(QString filepath,QVector<QStringList> v);
    void xlsByODBC(QString filepath,QVector<QStringList> v);
    dump();

    QVector<QString> rowMark;
    QVector<QString> rowName;
    QVector<QString> spaceCode;
    int ROWNUM;

};

#endif // DUMP_H
