#ifndef SCREENDB_H
#define SCREENDB_H


#include <QString>
#include <QList>

class ScreenDB
{
public:
    ScreenDB();

    void loadxlsByODBC(QString filePath);

private:

    QList<QString> companyCode;


};

#endif // SCREENDB_H
