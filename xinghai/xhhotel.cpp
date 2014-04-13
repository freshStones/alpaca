#include "xhhotel.h"

xhhotel::xhhotel(QString customerID,QString signStr)
{
    this->customerID = customerID;
    this->signStr = signStr;
    soap = new BasicHttpBinding_USCOREixinghaiProxy();
}

QJsonObject xhhotel::jsonHandler(QString json)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8(),&err);
    if (err == QJsonParseError::NoError)
    {
        if (doc.isObject())
        {
            return doc.object();
        }
    }

}

void xhhotel::getHotelList(QString lastAccessDate)
{
    _tempuri__Get_USCOREHotel_USCOREList req;
    _tempuri__Get_USCOREHotel_USCOREListResponse res;
    req.LastAccessDate = &lastAccessDate;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    soap->Get_USCOREHotel_USCOREList(&req,&res);
    jsonHandler(res.Get_USCOREHotel_USCOREListResult);
}

void xhhotel::getHotelInfo(int hotelID)
{
    _tempuri__Get_USCOREHotel_USCOREInfo req;
    _tempuri__Get_USCOREHotel_USCOREInfoResponse res;
    req.HotelID = &hotelID;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    soap->Get_USCOREHotel_USCOREInfo(&req,&res);
    jsonHandler(res.Get_USCOREHotel_USCOREInfoResult);
}

void xhhotel::getHotelPrice(int hotelID, QString roomID, QString startDate, QString endDate)
{
    _tempuri__Get_USCOREHotel_USCOREPrice req;
    _tempuri__Get_USCOREHotel_USCOREPriceResponse res;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    req.HotelID = &hotelID;
    req.RoomID = &roomID;
    req.StartDate = &startDate;
    req.EndDate = &endDate;
    soap->Get_USCOREHotel_USCOREPrice(&res,&req);
    jsonHandler(res.Get_USCOREHotel_USCOREPriceResult);
}

void xhhotel::getHotelRoomState(int hotelID, QString roomID, QString startDate, QString endDate)
{
    _tempuri__Get_USCOREHotel_USCORERoomState req;
    _tempuri__Get_USCOREHotel_USCORERoomStateResponse res;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    req.HotelID = &hotelID;
    req.RoomID = &roomID;
    req.StartDate = &startDate;
    req.EndDate = &endDate;
    soap->Get_USCOREHotel_USCORERoomState(&req,&res);
    jsonHandler(res.Get_USCOREHotel_USCORERoomStateResult);
}
