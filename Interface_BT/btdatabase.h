#ifndef BTDATABASE_H
#define BTDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>


class btDatabase
{
public:

    static btDatabase* instance();

    void init();
    bool isOpen();

    int execSQL(const QString sql);
    QSqlQuery querySQL(const QString sql, bool debug = 0);
    int insertOperation(const QString sql);
    int updateOperation(const QString sql);

    void commitOperation();

private:
    static btDatabase* _instance;

    btDatabase();
    QSqlDatabase *db;
};

#endif // BTDATABASE_H
