#include "btdatabase.h"

btDatabase * btDatabase::_instance = 0;

void btDatabase::init()
{
    QSqlDatabase *db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QMYSQL");
    db->setHostName("localhost");
    db->setDatabaseName("LH_AirTicket");
    db->setUserName("root");
    db->setPassword("root");
    db->open();

    this->db = db;
}

btDatabase * btDatabase::instance()
{
    //qDebug() << "btDatabase::instance() called" << endl;
    if(btDatabase::_instance == 0){
        btDatabase::_instance = new btDatabase();
        btDatabase::_instance->init();
    }

    if(!btDatabase::_instance->isOpen()){
        delete btDatabase::_instance;
        btDatabase::_instance = 0;
        return btDatabase::instance();
    }

    return btDatabase::_instance;
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

void btDatabase::commitOperation()
{
    QString sql = "commit;";
    this->execSQL(sql);
}

