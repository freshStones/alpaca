#ifndef OTA_XMLHTTP_H
#define OTA_XMLHTTP_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QIODevice>
#include <QFile>

class OTA_XMLHTTP : public QObject
{
    Q_OBJECT
public:
    explicit OTA_XMLHTTP(QObject *parent = 0);
    ~OTA_XMLHTTP();

    //http post request, get xml-pattern response
    QString GetResponse(QString requestXML);

    QString genXMLAirAvail();       //国内航班可用舱位查询(AV)
    QString genXMLAirSegPrice();    //国内运价计算(PATA按航段)
    QString genXMLAirBrief();       //航班飞行时间(FF)
    QString genXMLAirDetails();     //航班经停信息(DSG)
    QString genXMLAirFareDisplay(); //国内公布运价查询(FD)
    QString genXMLAirBook();        //PNR预订(SellSeat)
    QString genXMLAirRuleDisplay(); //国内规则查询
    QString genXMLAirBookModify();  //PNR修改(PnrManage)
    QString genXMLAirResRet();      //提取PNR(RT)
    QString genXMLAirResRetComplete();//提取PNR历史记录(RTC)
    QString genXMLAirPrice();       //国内运价计算(PATA按PNR)
    QString genXMLAirDemandTicket();//出票(ETDZ)
    QString genXMLAirTicketVoid();  //废票(VT)
    QString genXMLAirTicketRetry(); //客票重出(ETRY)
    QString genXMLAirTicketRet();   //提取票面(DETR)
    QString genXMLAirTicketSuspend();//客票挂起(VSS/S)
    QString genXMLAirTicketResume();//客票解挂(VSS/B)
    QString genXMLQMsg();           //Q信息处理

    const QString &getLastErrorMessage();
    void setErrorMessage(const QString &msg);

private:
    QNetworkAccessManager *_postManager;
    QNetworkRequest *_request;
    QNetworkReply *_reply;
    QString _errMsg;
    QString usr;
    QString pwd;
    QString requestURL;
    
signals:
    
public slots:
    void replyFinished(QNetworkReply*);
    void slotError(QNetworkReply::NetworkError);
    void slotReadyRead();
    void handleTimeOut();
    
};

#endif // OTA_XMLHTTP_H
