#ifndef XHHOTEL_H
#define XHHOTEL_H
#include "gsoap/soapBasicHttpBinding_USCOREixinghaiProxy.h"
#include <QString>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

class xhhotel
{
public:
    xhhotel(QString customerID,QString signStr);
    QJsonObject jsonHandler(std::wstring* data);
    void getHotelList(std::wstring);
    void getHotelInfo(int);
    void getHotelPrice(int,std::wstring,std::wstring,std::wstring);
    void getHotelRoomState(int,std::wstring,std::wstring,std::wstring);
private:
    BasicHttpBinding_USCOREixinghaiProxy *soap;
    std::wstring customerID,signStr;
};

#endif // XHHOTEL_H
