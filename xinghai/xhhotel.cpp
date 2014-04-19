#include "xhhotel.h"
#include <QDebug>
QString xhhotel::sqlCollection = "";
xhhotel::xhhotel(QString customerID,QString signStr)
{
    this->customerID = customerID.toStdWString();
    this->signStr = signStr.toStdWString();
    soap = new BasicHttpBinding_USCOREixinghaiProxy();
    soap_set_mode(soap->soap,SOAP_C_UTFSTRING);
}

QJsonObject xhhotel::jsonHandler(std::wstring* data)
{
    QString json = QString().fromStdWString(*data);
    qDebug()<<json;
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

void xhhotel::genquery(QString tbname,QJsonArray array,QString pkeyname,QString fkeyname,QString fkeyval,int insertflag)
{
    for (int i = 0; i < array.size(); i++)
    {
        QJsonObject cur = array.at(i).toObject();
        if(fkeyname!="")
        {
            cur.insert(fkeyname,fkeyval);
        }
        genquery(tbname,cur,pkeyname,insertflag);
    }
    //qDebug()<<sqlCollection;
}

void xhhotel::genquery(QString tbname,QJsonObject map,QString pkeyname,int insertflag)
{
    QStringList key,value;
    QString keyval;
    for (QJsonObject::iterator it = map.end()-1;it != map.begin()-1; it--)
    {
        if (it.key()==pkeyname)
        {
            keyval = it.value().toString();
        }
        if (it.key() == "RoomTypeList")
        {
            genquery("hotelroomtypelist",it.value().toArray(),"roomid",pkeyname,keyval,insertflag);
        }
        else if (it.key() == "AdditionalProduct")
            genquery("hoteladditionalproduct",it.value().toArray(),"productid",pkeyname,keyval);
        else if (it.key() == "SaleRemark")
            genquery("hotelsaleremark",it.value().toArray(),"remarkid",pkeyname,keyval);
        else if (it.key() == "RoomPrice")
        {
            insertflag = 0;
            genquery("hotelroomprice",it.value().toArray(),"priceid",pkeyname,keyval);
            //QString query = QString("update %1 set %2=%3 where%4=%5; ").arg(tbname).arg("roomtypecount").arg(map["RoomTypeCount"].toString()).arg(pkeyname).arg(keyval);
            //sqlCollection += query;
        }
        else
        {
            value.append("'" + it.value().toString() + "'");
            key.append(it.key());
        }
    }
    if (insertflag)
    {
        QString query = QString("replace into %1(%2) values(%3); ").arg(tbname).arg(key.join(",")).arg(value.join(","));
        sqlCollection += query;
    }
}


void xhhotel::getHotelList(std::wstring lastAccessDate)
{
    _tempuri__Get_USCOREHotel_USCOREList req;
    _tempuri__Get_USCOREHotel_USCOREListResponse res;
    req.LastAccessDate = &lastAccessDate;
    req.CustomerID = &customerID;
    req.SignStr = &signStr;
    soap->Get_USCOREHotel_USCOREList(&req,&res);

    QJsonObject jsonobj = jsonHandler(res.Get_USCOREHotel_USCOREListResult);
    QJsonArray array = jsonobj["HotelList"].toArray();
    genquery("hotellist",array,"hotelid");
    xhDatabase::instance()->insertOperation(sqlCollection);
    sqlCollection = "";
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
    genquery("hotelinfo",jsonobj,"hotelid");
    qDebug()<<sqlCollection;
    xhDatabase::instance()->insertOperation(sqlCollection);
    sqlCollection = "";

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
    genquery("hotelprice",jsonobj["RoomTypeList"].toArray(),"roomid","","",0);
    qDebug()<<sqlCollection;
    xhDatabase::instance()->insertOperation(sqlCollection);
    sqlCollection = "";
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
