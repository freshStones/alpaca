#ifndef QUNARPOLICYAPI_H
#define QUNARPOLICYAPI_H

#include <QString>
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
class QunarPolicyAPI
{
public:
    QunarPolicyAPI();
    QString toZip(QString filename);
    QString domToFile(QDomDocument doc);
    QDomDocument uploadPolicy();
};

#endif // QUNARPOLICYAPI_H
