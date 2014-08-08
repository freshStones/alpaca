#ifndef ALIAPP_H
#define ALIAPP_H
#include<QString>
#include<QMap>
#include<QtNetwork/QNetworkRequest>
#include<QUrl>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QStringList>
class aliapp : QObject
{
    Q_OBJECT
public slots:
    void replyFinished(QNetworkReply* reply);
public:
    aliapp();
    void execute(QMap<QString,QString> map);
};

#endif // ALIAPP_H
