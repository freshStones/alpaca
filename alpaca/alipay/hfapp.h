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
    void execute(QVector<QPair<String,String> > data, QVector<QPair<String, String> > resdata);
    void readMessage();
};

#endif // HFAPP_H
