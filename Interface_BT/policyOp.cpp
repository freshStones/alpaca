#include "policyOp.h"
#include "gsoap/BaitourServiceSoap.nsmap"
using namespace std;
#include <QDebug>
policyOp::policyOp()
{
    BTproxy = new BaitourServiceSoapProxy();
    username = "lhjk";
    pwd = "lhjk";
    agentCode = "B2B_070745";
}

bool policyOp::showDebugMsg(string msg)
{
    qDebug() << msg.c_str() << endl;
    return true;
}
bool policyOp::GetAllCommonPolicy(string tripType = "0",string ticketType = "0")
{
    _ns1__GetAllCommonPolicy req;
    _ns1__GetAllCommonPolicyResponse res;
    req.tripType = &tripType;
    req.ticketType = &ticketType;
    req.agentUserName = &username;
    req.pwd = &pwd;
    BTproxy->GetAllCommonPolicy(&req, &res);

//    showDebugMsg(res.GetAllCommonPolicyResult);
    return true;
}

bool policyOp::GetAllCommonPolicyZIP()
{
    return true;
}
bool policyOp::GetAlterCommonPolicy(string rQStartDateTime,string tripType,string ticketType)
{
    _ns1__GetAlterCommonPolicy req;
    _ns1__GetAlterCommonPolicyResponse res;
    req.agentUserName = &username;
    req.pwd = &pwd;
    req.rQStartDateTime = &rQStartDateTime;
    req.tripType = &tripType;
    req.ticketType = &ticketType;
    BTproxy ->GetAlterCommonPolicy(&req,&res);
    return true;
}
bool policyOp::GetAVPolicy(string DepartureDateTime,string FlightNumber,string ResBookDesigCode,string DepartureAirport,string ArrivalAirport,string ReturnPolicyType,string TripType,string FlightNumberBack,string ResBookDesigCodeBack,string DepartureDateTimeBack)
{
    _ns1__GetAVPolicy req;
    _ns1__GetAVPolicyResponse res;
    QString xml = QString("<OTA_AirFareRQ	 AgentCode=\"%1\" AgentUserName=\"%2\" AgentPwd=\"%3\" DepartureDateTime='%4' FlightNumber='%5' ResBookDesigCode='%6' DepartureAirport='%7' ArrivalAirport='%8' ReturnPolicyType='%9'  TripType='%10' FlightNumberBack='%11' ResBookDesigCodeBack='%12' DepartureDateTimeBack='%13'></OTA_AirFareRQ>").arg(agentCode).arg(username).arg(pwd)
            .arg(DepartureDateTime).arg(FlightNumber).arg(ResBookDesigCode).arg(DepartureAirport).arg(ArrivalAirport).arg(ReturnPolicyType).arg(TripType).arg(FlightNumberBack).arg(ResBookDesigCodeBack).arg(DepartureDateTimeBack);
    req.xmlDoc = &(xml.toStdString());
    BTproxy ->GetAVPolicy(&req,&res);
    return true;
}
bool policyOp::GetChangeFlightDate()
{
    return true;
}
bool policyOp::GetDomesticMatchNormalZRateByID()
{
    return true;
}
bool policyOp::GetInvalidationProviders()
{
    return true;
}
bool policyOp::GetOrderInfo()
{
    return true;
}
bool policyOp::DetailCreateOrder()
{
    return true;
}
bool policyOp::MatchCommonPolicy()
{
    return true;
}

bool policyOp::RefundOrder()
{
    return true;
}

bool policyOp::RTCreateOrder()
{
    return true;
}
