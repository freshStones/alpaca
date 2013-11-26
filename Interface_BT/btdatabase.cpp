#include "btdatabase.h"

btDatabase * btDatabase::_instance = 0;

void btDatabase::init()
{
    QSqlDatabase *db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QMYSQL");
    db->setHostName("162.105.30.115");
    db->setDatabaseName("LH_AirTicket");
    db->setUserName("remote");
    db->setPassword("alpaca");
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

int btDatabase::batchOperation(const QString sql)
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
    return res;
}

void btDatabase::commitOperation()
{
    QString sql = "commit;";
    this->execSQL(sql);
}

