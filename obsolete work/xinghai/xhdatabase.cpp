#include "xhDatabase.h"
#include <QDebug>
xhDatabase * xhDatabase::_instance = 0;
void xhDatabase::init()
{
    QSqlDatabase *db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QMYSQL");
    db->setHostName("112.124.104.95");
    db->setDatabaseName("lhly");
    db->setUserName("remote");
    db->setPassword("team2022");
    //qDebug()<<server<<username<<password;
    db->open();

    this->db = db;
}

xhDatabase * xhDatabase::instance()
{
    //qDebug() << "xhDatabase::instance() called" << endl;
    if(xhDatabase::_instance == 0){
        xhDatabase::_instance = new xhDatabase();
        xhDatabase::_instance->init();
        return xhDatabase::_instance;
    }

    if(!xhDatabase::_instance->isOpen()){
        delete xhDatabase::_instance;
        xhDatabase::_instance = 0;
        return xhDatabase::instance();
    }

    return xhDatabase::_instance;
}

xhDatabase::xhDatabase()
{
}

bool xhDatabase::isOpen()
{
    QSqlQuery q;
    return (q.exec("select 1;") == true);
}

int xhDatabase::execSQL(const QString sql)
{
    QSqlQuery q;
    q.prepare(sql);
    return (q.exec() == true);
}

QSqlQuery xhDatabase::querySQL(const QString sql, bool debug)
{
    if(debug) qDebug() << sql << endl;
    QSqlQuery q;
    q.prepare(sql);
    q.exec();
    return q;
}

int xhDatabase::insertOperation(const QString sql)
{
    return this->execSQL(sql);
}

int xhDatabase::updateOperation(const QString sql)
{
    return this->execSQL(sql);
}

int xhDatabase::batchOperation(const QString sql)
{
    int res = 0;
    if(QSqlDatabase::database().driver()->hasFeature(QSqlDriver::Transactions))
    {
        QSqlDatabase::database().transaction();
        QSqlQuery query;
        qDebug() << "start sql op" << endl;
        try{
            res = query.exec(sql);
            QSqlDatabase::database().commit();
        }
        catch(QString Exception){
            qDebug() << Exception << endl;
        }

        //qDebug() << sql << endl;
        qDebug() << "sql op ended" << endl;
    }
    else
    {
        qDebug()<<"else";
    }
    return res;
}
