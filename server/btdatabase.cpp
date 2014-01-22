#include "btdatabase.h"
#include <QDebug>
btDatabase * btDatabase::_instance = 0;
QString btDatabase::username;
QString btDatabase::password;
QString btDatabase::server;
void btDatabase::init()
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
    else qDebug() << "database open failed.";

    this->db = db;
}

btDatabase * btDatabase::instance()
{
//    qDebug() << "btDatabase::instance() called" << endl;
    if(btDatabase::_instance == 0){
        btDatabase::_instance = new btDatabase();
        btDatabase::_instance->init();
        return btDatabase::_instance;
    }

    if(!btDatabase::_instance->isOpen()){
        delete btDatabase::_instance;
        btDatabase::_instance = 0;
        return btDatabase::instance();
    }
    return btDatabase::_instance;
}

void btDatabase::setconfig(const QString _username,const  QString _password,const QString _server)
{
    btDatabase::username = _username;
    btDatabase::password = _password;
    btDatabase::server = _server;
}

btDatabase::btDatabase()
{
}

bool btDatabase::isOpen()
{
    QSqlQuery q;
    return (q.exec("select 1;") == true);
}

int btDatabase::execSQL(const QString sql)
{
    QSqlQuery q;
    q.prepare(sql);
    return (q.exec() == true);
}

QSqlQuery btDatabase::querySQL(const QString sql, bool debug)
{
    if(debug) qDebug() << sql << endl;
    QSqlQuery q;
    q.prepare(sql);
    q.exec();
    return q;
}

int btDatabase::insertOperation(const QString sql)
{
    return this->execSQL(sql);
}

int btDatabase::updateOperation(const QString sql)
{
    return this->execSQL(sql);
}

int btDatabase::batchOperation(const QString sql)
{
    int res = 0;
//  if(QSqlDatabase::database().driver()->hasFeature(QSqlDriver::Transactions))
    if(db->driver()->hasFeature(QSqlDriver::Transactions))
    {
        db->transaction();
//        qDebug() << "start sql op." ;
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
//        qDebug() << "sql op ended." << count << " rows affected.";
    }
    return res;
}

QString btDatabase::identify(const QString usr, const QString pwd)
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

void btDatabase::commitOperation()
{
    QString sql = "commit;";
    this->execSQL(sql);
}

