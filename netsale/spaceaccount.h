#ifndef SPACEACCOUNT_H
#define SPACEACCOUNT_H

#include <QMap>
#include <QString>

class spaceAccount
{
public:
    spaceAccount();

    static void initMap();

public:
    static QMap<QString, QString> spaceMap;

};

#endif // SPACEACCOUNT_H
