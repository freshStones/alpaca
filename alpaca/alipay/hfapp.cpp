#include "hfapp.h"

hfapp::hfapp()
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    blockSize = 0; //初始化其为0
    tcpSocket->abort(); //取消已有的连接
    tcpSocket->connectToHost(XXXXXXX,6180);

}

void hfapp::execute(QVector<QPair<QString, QString> > data,QVector<QPair<String, String> > resdata)
{
    QString str = "";
    QVector<QPair<String, String> >::Iterator it = data.begin();
    for(;it != data.end(); it++)
    {
        str += it->first + "=" + it->second;
    }
    str += QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5 );
    for(it = resdata.begin(); it != resdata.end(); it++)
    {
        str += it->first + "=" + it->second;
    }
    tcpSocket->write(str);
}

void hfapp::readMessage()
{
//xml
}
