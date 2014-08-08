#ifndef OTA_XMLHTTP2_H
#define OTA_XMLHTTP2_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QtNetwork>
//#include <iostream>
//#include <QtNetwork/QHttp>


class OTA_XMLHTTP2 : public QObject
{
    Q_OBJECT
public:
    explicit OTA_XMLHTTP2(QObject *parent = 0);
    
    QString GetResponse(QString requestXML);

private:
    QString usr;
    QString pwd;
    QUrl url;
    QHttp *_qhttp;
    QFile *_rssfile;

signals:
    void finished();
    
public slots:
    void done(bool error);
};

#endif // OTA_XMLHTTP2_H
