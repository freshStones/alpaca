#ifndef OTA_XMLHTTP_H
#define OTA_XMLHTTP_H

#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QObject>

class OTA_XMLHTTP
{
public:
    OTA_XMLHTTP();

    //http post request, get xml-pattern response
    QString GetResponse(QString requestXML);

    //国内航班可用舱位查询(AV)
    QString genXMLAirAvail();

    //国内运价计算(PATA按航段)
    QString genXMLAirSegPrice();

    //航班飞行时间(FF)
    QString genXMLAirBrief();

    //航班经停信息(DSG)
    QString genXMLAirDetails();

    //国内公布运价查询(FD)
    QString genXMLAirFareDisplay();

    //PNR预订(SellSeat)
    QString genXMLAirBook();

    //国内规则查询
    QString genXMLAirRuleDisplay();

    //PNR修改(PnrManage)
    QString genXMLAirBookModify();

    //提取PNR(RT)
    QString genXMLAirResRet();

    //提取PNR历史记录(RTC)
    QString genXMLAirResRetComplete();

    //国内运价计算(PATA按PNR)
    QString genXMLAirPrice();

    //出票(ETDZ)
    QString genXMLAirDemandTicket();

    //废票(VT)
    QString genXMLAirTicketVoid();

    //客票重出(ETRY)
    QString genXMLAirTicketRetry();

    //提取票面(DETR)
    QString genXMLAirTicketRet();

    //客票挂起(VSS/S)
    QString genXMLAirTicketSuspend();

    //客票解挂(VSS/B)
    QString genXMLAirTicketResume();

    //Q信息处理
    QString genXMLQMsg();

private:
    QString usr;
    QString pwd;
    QString requestURL;

public slots:
    void replyFinished(QNetworkReply *);    /*http post request finished*/

};

#endif // OTA_XMLHTTP_H
