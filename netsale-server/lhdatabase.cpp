#include "lhdatabase.h"
#include <QDebug>
#include <QSqlError>
lhdatabase * lhdatabase::_instance = 0;
QString lhdatabase::username;
QString lhdatabase::password;
QString lhdatabase::server;
void lhdatabase::init()
{
    QSqlDatabase *db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QMYSQL");
//    db->setHostName("192.168.1.170");
    db->setHostName("localhost");
    db->setDatabaseName("LH_AirTicket");
//    db->setUserName("remote");
//    db->setPassword("tm2022");
    db->setUserName("root");
    db->setPassword("alpaca");
    if(db->open())
        qDebug() << "database opened.";
    else qDebug() << "database open failed."<<db->lastError();

    this->db = db;
}

lhdatabase * lhdatabase::instance()
{
//    qDebug() << "lhdatabase::instance() called" << endl;
    if(lhdatabase::_instance == 0){
        lhdatabase::_instance = new lhdatabase();
        lhdatabase::_instance->init();
        return lhdatabase::_instance;
    }

    if(!lhdatabase::_instance->isOpen()){
        delete lhdatabase::_instance;
        lhdatabase::_instance = 0;
        return lhdatabase::instance();
    }
    return lhdatabase::_instance;
}

void lhdatabase::setconfig(const QString _username,const  QString _password,const QString _server)
{
    lhdatabase::username = _username;
    lhdatabase::password = _password;
    lhdatabase::server = _server;
}

lhdatabase::lhdatabase()
{
}

bool lhdatabase::isOpen()
{
    QSqlQuery q;
    return (q.exec("select 1;") == true);
}

int lhdatabase::execSQL(const QString sql)
{
    QSqlQuery q;
    q.prepare(sql);
    return (q.exec() == true);
}

QSqlQuery lhdatabase::querySQL(const QString sql, bool debug)
{
    if(debug) qDebug() << sql << endl;
    QSqlQuery q;
    q.prepare(sql);
    q.exec();
    return q;
}

int lhdatabase::insertOperation(const QString sql)
{
    return this->execSQL(sql);
}

int lhdatabase::updateOperation(const QString sql)
{
    return this->execSQL(sql);
}

int lhdatabase::batchOperation(const QString sql)
{
    int res = 0;
//  if(QSqlDatabase::database().driver()->hasFeature(QSqlDriver::Transactions))
    if(db->driver()->hasFeature(QSqlDriver::Transactions))
    {
        db->transaction();
        qDebug() << "start sql op." ;
        try{
            res = this->execSQL(sql);
            db->commit();
        }
        catch(QString Exception){
            qDebug() << Exception << endl;
        }

        int count = 0;
        for(int i = 0; i < sql.length(); i++){
            if(sql.at(i) == ';') count++;
        }

//        qDebug() << sql << endl;
        qDebug() << "sql op ended." << count << " rows affected.";
    }
    return res;
}

QString lhdatabase::identify(const QString usr, const QString pwd)
{
    QString sql = QString("SELECT authorityType FROM LH_AirTicket.userList WHERE userAccount='%1' AND userPassport='%2';").arg(usr).arg(pwd);
    QSqlQuery q(sql);
    qDebug() << sql;
    try
    {
        q.exec(sql);
    }
    catch(QString exception){
        //QMessageBox::warning(NULL,QObject::tr("Warning"),QObject::tr(exception.toStdString().data()),QMessageBox::Ok);
    }
    if(q.next())    return QString(q.value(0).toString());
    else return "unauthorized id";
}

void lhdatabase::commitOperation()
{
    QString sql = "commit;";
    this->execSQL(sql);
}

