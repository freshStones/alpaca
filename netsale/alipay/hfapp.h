#ifndef HFAPP_H
#define HFAPP_H
#include<QtNetwork/QTcpSocket>
#include<QPair>
#include<QVector>
#include<QCryptographicHash>
class hfapp
{
    QTcpSocket * tcpSocket;
public:
    hfapp();
    void execute(QVector<QPair<QString,QString> > data, QVector<QPair<QString, QString> > resdata);
    void readMessage();
};

#endif // HFAPP_H
