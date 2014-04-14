#include "xhhotel.h"
#include <QDebug>
xhhotel::xhhotel(QString customerID,QString signStr)
{
    this->customerID = customerID.toStdWString();
    this->signStr = signStr.toStdWString();
    soap = new BasicHttpBinding_USCOREixinghaiProxy();
}

QJsonObject xhhotel::jsonHandler(std::wstring* data)
{
    QString json = QString().fromStdWString(*data);
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8(),&err);
    if (err.error == QJsonParseError::NoError)
    {
        if (doc.isObject())
        {
            return doc.object();
        }
    }
    //return NULL;
}



void xhhotel::getHotelList(std::wstring lastAccessDate)
{
    _tempuri__Get_USCOREHotel_USCOREList req;
    _tempuri__Get_USCOREHotel_USCOREListResponse res;
    req.LastAccessDate = &lastAccessDate;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    soap->Get_USCOREHotel_USCOREList(&req,&res);
    qDebug()<<soap->soap_fault_detail();
    //qDebug()<<res.Get_USCOREHotel_USCOREListResult->length();
    //QJsonObject jsonobj = jsonHandler(res.Get_USCOREHotel_USCOREListResult);

    QString hotelID,hotelName,hotelStatus,infoUpdate,priceUpdate,statusUpdate;
}

void xhhotel::getHotelInfo(int hotelID)
{
    _tempuri__Get_USCOREHotel_USCOREInfo req;
    _tempuri__Get_USCOREHotel_USCOREInfoResponse res;
    req.HotelID = &hotelID;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    soap->Get_USCOREHotel_USCOREInfo(&req,&res);
    QJsonObject jsonobj = jsonHandler(res.Get_USCOREHotel_USCOREInfoResult);

    //QString hotelName,hotelEName,province,city,zone,hotelstarts,phone,fax,website,postcode,address,opendate;
    //QString roomcount,funds,beach,lon,lat,info,recommend;
    //QString roomID,masterID,masterName,roomName,startDate,endDate,bedType,breakfast,advance,daylimit;
    //QString countlimit,flooor,area,hasNetwork,structure,description;
    //QString productID,productName,price,unit,startDate,endDate,remark;
    //QString remarkstartdate,remarkenddate,remarktext;
}

void xhhotel::getHotelPrice(int hotelID, std::wstring roomID, std::wstring startDate, std::wstring endDate)
{
    _tempuri__Get_USCOREHotel_USCOREPrice req;
    _tempuri__Get_USCOREHotel_USCOREPriceResponse res;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    req.HotelID = &hotelID;
    req.RoomID = &roomID;
    req.StartDate = &startDate;
    req.EndDate = &endDate;
    soap->Get_USCOREHotel_USCOREPrice(&req,&res);
    QJsonObject jsonobj = jsonHandler(res.Get_USCOREHotel_USCOREPriceResult);
}

void xhhotel::getHotelRoomState(int hotelID, std::wstring roomID, std::wstring startDate, std::wstring endDate)
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
    QJsonObject jsonobj = jsonHandler(res.Get_USCOREHotel_USCORERoomStateResult);
}
