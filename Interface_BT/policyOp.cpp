#include "policyOp.h"
#include "gsoap/BaitourServiceSoap.nsmap"


policyOp::policyOp(QString _usrName, QString _pwd, QString _agentcode)
{
    BTproxy = new BaitourServiceSoapProxy();
    usrName = _usrName;
    pwd = _pwd;
    agentCode = _agentcode;
}

bool policyOp::showDebugMsg(QString msg)
{
    qDebug() << msg << endl;
    return true;
}
bool policyOp::xmlhandler(int callRes,QString xml,bool (*visitor)(QDomElement))
{
    if(callRes == SOAP_OK){
        QDomDocument doc;
        QString errorMSG;
        int errLine = 0, errCol = 0;
        if(!doc.setContent(xml, &errorMSG, &errLine, &errCol)){
            showDebugMsg(QString("Parse file failed at line %1 column %2, error: %3 !").arg(errLine).arg(errCol).arg(errorMSG));
            return false;
        }
        else{
            showDebugMsg("Parse Succeeded!");
        }

        if(doc.isNull()){
            showDebugMsg("Document is null!");
            return false;
        }

        QDomElement root = doc.documentElement();
        QDomElement element = root.firstChildElement();
        //int count  = 0;
        while(!element.isNull()){
            visitor(element);
            element = element.nextSiblingElement();
        }

    }
    else{
        showDebugMsg(QString("GetAllCommonPolicy call failed. Error code: %1").arg(callRes));
    }
}
bool policyOp::GetAllCommonPolicy(QString tripType = "0",QString ticketType = "0")
{
    return this->GetAllCommonPolicy(tripType.toStdString(), ticketType.toStdString(), this->usrName.toStdString(),this->pwd.toStdString());
}

bool policyOp::GetAllCommonPolicy(std::string tripType, std::string ticketType, std::string username, std::string pwd)
{
    _ns1__GetAllCommonPolicy req;
    _ns1__GetAllCommonPolicyResponse res;
    req.tripType = &tripType;
    req.ticketType = &ticketType;
    req.agentUserName = &username;
    req.pwd = &pwd;
    int callRes = BTproxy->GetAllCommonPolicy(&req, &res);
    if(callRes == SOAP_OK){
        QDomDocument doc;
        QString errorMSG;
        int errLine = 0, errCol = 0;
        if(!doc.setContent(QString().fromStdString(*res.GetAllCommonPolicyResult), &errorMSG, &errLine, &errCol)){
            showDebugMsg(QString("Parse file failed at line %1 column %2, error: %3 !").arg(errLine).arg(errCol).arg(errorMSG));
            return false;
        }
        else{
            showDebugMsg("Parse Succeeded!");
        }

        if(doc.isNull()){
            showDebugMsg("Document is null!");
            return false;
        }

        QDomElement root = doc.documentElement();
        QDomElement element = root.firstChildElement();
        int count  = 0;
        while(!element.isNull()){
            qDebug() << element.nodeName() << endl;
            element = element.nextSiblingElement();
            count++;
        }
        qDebug() << count << endl;
    }
    else{
        showDebugMsg(QString("GetAllCommonPolicy call failed. Error code: %1").arg(callRes));
    }

    //showDebugMsg(QString().fromStdString(*res.GetAllCommonPolicyResult));
}

bool policyOp::GetAllCommonPolicyZIP()
{
    return true;
}
bool policyOp::GetAlterCommonPolicy(QString rQStartDateTime, QString tripType, QString ticketType)
{
    return this->GetAlterCommonPolicy(rQStartDateTime.toStdString(),tripType.toStdString(),ticketType.toStdString(),this->usrName.toStdString(),this->pwd.toStdString());
}

bool policyOp::GetAlterCommonPolicy(string rQStartDateTime,string tripType,string ticketType,string usrname,string pwd)
{
    _ns1__GetAlterCommonPolicy req;
    _ns1__GetAlterCommonPolicyResponse res;
    req.agentUserName = &usrname;
    req.pwd = &pwd;
    req.rQStartDateTime = &rQStartDateTime;
    req.tripType = &tripType;
    req.ticketType = &ticketType;
    int callRes = BTproxy ->GetAlterCommonPolicy(&req,&res);
    this->xmlhandler(callRes,QString().fromStdString(*res.GetAlterCommonPolicyResult),GetAlterCommonPolicyVisitor);
    return true;
}
bool policyOp::GetAlterCommonPolicyVisitor(QDomElement element)
{
    QMap<QString,QString> map;
    map.insert("Id",element.attributes().namedItem("Id").nodeValue());
    map.insert("State",element.attributes().namedItem("State").nodeValue());
    map.insert("IsChangePnr",element.attributes().namedItem("IsChangePnr").nodeValue());
    map.insert("ProviderWorkTime",element.attributes().namedItem("ProviderWorkTime").nodeValue());
    map.insert("ProviderVworkTime",element.attributes().namedItem("ProviderVWorkTime").nodeValue());
    map.insert("Value",element.toText().data());
    return true;
}
bool policyOp::GetAVPolicy(QString DepartureDateTime, QString FlightNumber, QString ResBookDesigCode,QString DepartureAirport,QString ArrivalAirport, QString ReturnPolicyType, QString TripType, QString FlightNumberBack, QString ResBookDesigCodeBack, QString DepartureDateTimeBack)
{
    return this->GetAVPolicy(DepartureDateTime.toStdString(),FlightNumber.toStdString(),ResBookDesigCode.toStdString(),DepartureAirport.toStdString(),ArrivalAirport.toStdString(),ReturnPolicyType.toStdString(),TripType.toStdString(),FlightNumberBack.toStdString(),ResBookDesigCodeBack.toStdString(),DepartureDateTimeBack.toStdString(),this->usrName.toStdString(),this->pwd.toStdString(),this->agentCode.toStdString());
}
bool policyOp::GetAVPolicy(string DepartureDateTime,string FlightNumber,string ResBookDesigCode,string DepartureAirport,string ArrivalAirport,string ReturnPolicyType,string TripType,string FlightNumberBack,string ResBookDesigCodeBack,string DepartureDateTimeBack,string usrname,string pwd,string agentCode)
{
    _ns1__GetAVPolicy req;
    _ns1__GetAVPolicyResponse res;
    QString xml = QString("<OTA_AirFareRQ	 AgentCode=\"%1\" AgentUserName=\"%2\" AgentPwd=\"%3\" DepartureDateTime='%4' FlightNumber='%5' ResBookDesigCode='%6' DepartureAirport='%7' ArrivalAirport='%8' ReturnPolicyType='%9'  TripType='%10' FlightNumberBack='%11' ResBookDesigCodeBack='%12' DepartureDateTimeBack='%13'></OTA_AirFareRQ>").arg(agentCode).arg(usrname).arg(pwd)
            .arg(DepartureDateTime).arg(FlightNumber).arg(ResBookDesigCode).arg(DepartureAirport).arg(ArrivalAirport).arg(ReturnPolicyType).arg(TripType).arg(FlightNumberBack).arg(ResBookDesigCodeBack).arg(DepartureDateTimeBack);
    xmldoc = xml.toStdString();
    req.xmlDoc = &xmldoc;
    int callRes = BTproxy ->GetAVPolicy(&req,&res);
    this->xmlhandler(callRes,QString().fromStdString(*res.GetAVPolicyResult),GetAVPolicyVisitor);
    return true;
}
bool policyOp::GetAVPolicyVisitor()
{

}
bool policyOp::MatchCommonPolicy(QString DepartureDateTime,QString FlightNumber,QString ResBookDesigCode,QString DepartureAirport,QString ArrivalAirport,QString ReturnPolicyType,QString TripType,QString FlightNumberBack,QString ResBookDesigCodeBack,QString DepartureDateTimeBack)
{
    return this->MatchCommonPolicy(DepartureDateTime.toStdString(),FlightNumber.toStdString(),ResBookDesigCode.toStdString(),DepartureAirport.toStdString(),ArrivalAirport.toStdString(),ReturnPolicyType.toStdString(),TripType.toStdString(),FlightNumberBack.toStdString(),ResBookDesigCode.toStdString(),DepartureDateTimeBack.toStdString(),this->usrName.toStdString(),this->pwd.toStdString(),this->agentCode.toStdString());
}

bool policyOp::MatchCommonPolicy(string DepartureDateTime,string FlightNumber,string ResBookDesigCode,string DepartureAirport,string ArrivalAirport,string ReturnPolicyType,string TripType,string FlightNumberBack,string ResBookDesigCodeBack,string DepartureDateTimeBack,string usrname,string pwd,string agentCode)
{
    _ns1__MatchCommonPolicy req;
    _ns1__MatchCommonPolicyResponse res;

    this->xmlhandler();
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

bool policyOp::RefundOrder()
{
    return true;
}

bool policyOp::RTCreateOrder()
{
    return true;
}
