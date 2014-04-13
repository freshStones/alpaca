#ifndef XHHOTEL_H
#define XHHOTEL_H
#include "gsoap/soapBasicHttpBinding_USCOREixinghaiProxy.h"
#include <QString>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

class xhhotel
{
public:
    xhhotel();
    void jsonHandler(QString json);
    void getHotelList(QString);
    void getHotelInfo(int);
    void getHotelPrice(int,QString,QString,QString);
    void getHotelRoomState(int,QString,QString,QString);
private:
    BasicHttpBinding_USCOREixinghaiProxy *soap;
    QString customerID,signStr;
};

#endif // XHHOTEL_H
