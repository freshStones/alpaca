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
bool policyOp::GetAVPolicy(string Type,string OrderSrc,string DptAirport,string ArrAirport,string TakeOffDate,string Cabin,string FlightNum,string avinfo,string usrname,string pwd,string agentCode)
{
    _ns1__GetAVPolicy req;
    _ns1__GetAVPolicyResponse res;
    QString xml = QString("<FlightSearch AgentCode=\"%1\" AgentUserName=\"%2\" AgentPwd=\"%3\" ><AV  Type=\"%4\" OrderSrc=\"%5\"  DptAirport=\"%6\"  ArrAirport=\"%7\"  TakeOffDate=\"%8\" Cabin=\"%9\"  FlightNum=\"%10\">%11</AV></FlightSearch>").arg(agentCode).arg(usrname).arg(pwd).arg(Type).arg(OrderSrc).arg(DptAirport).arg(ArrAirport).arg(TakeOffDate).arg(Cabin).arg(FlightNum).arg(avinfo);
    xmldoc = xml.toStdString();
    req.xmlDoc = &xmldoc;
    int callRes = BTproxy ->GetAVPolicy(&req,&res);
    return this->xmlhandler(callRes,QString().fromStdString(*res.GetAVPolicyResult),GetAVPolicyVisitor);
}
bool policyOp::GetAVPolicyVisitor()
{
    QMap<QString,QString> map;
    map.insert("Dpt",element.attributes().namedItem("Dpt").nodeValue());
    map.insert("Arr",element.attributes().namedItem("Arr").nodeValue());
    map.insert("Date",element.attributes().namedItem("Date").nodeValue());
    map.insert("DptAirport",element.attributes().namedItem("DptAirport").nodeValue());
    map.insert("ArrAirport",element.attributes().namedItem("ArrAirport").nodeValue());
    map.insert("DptTime",element.attributes().namedItem("DptTime").nodeValue());
    map.insert("ArrTime",element.attributes().namedItem("ArrTime").nodeValue());
    map.insert("Carrier",element.attributes().namedItem("Carrier").nodeValue());
    map.insert("Code",element.attributes().namedItem("Code").nodeValue());
    map.insert("StanderPrice",element.attributes().namedItem("StanderPrice").nodeValue());
    map.insert("CabinYPrice",element.attributes().namedItem("CabinYPrice").nodeValue());
    map.insert("LowestCabinCode",element.attributes().namedItem("LowestCabinCode").nodeValue());
    map.insert("LowestPrice",element.attributes().namedItem("LowestPrice").nodeValue());
    map.insert("Meal",element.attributes().namedItem("Meal").nodeValue());
    map.insert("PlanType",element.attributes().namedItem("PlanType").nodeValue());
    map.insert("SeatsForSale",element.attributes().namedItem("SeatsForSale").nodeValue());
    map.insert("Message",element.attributes().namedItem("Message").nodeValue());
    map.insert("LowestChildPrice",element.attributes().namedItem("LowestChildPrice").nodeValue());
    map.insert("ChildCabin",element.attributes().namedItem("ChildCabin").nodeValue());
    map.insert("InsuranceName",element.attributes().namedItem("InsuranceName").nodeValue());
    map.insert("InsuranceCount",element.attributes().namedItem("InsuranceCount").nodeValue());
    map.insert("InsuranceMax",element.attributes().namedItem("InsuranceMax").nodeValue());
    map.insert("InsurancePrice",element.attributes().namedItem("InsurancePrice").nodeValue());
    map.insert("PolicyCode",element.attributes().namedItem("PolicyCode").nodeValue());
    map.insert("RateValue",element.attributes().namedItem("RateValue").nodeValue());
    map.insert("ChildStandardPrice",element.attributes().namedItem("ChildStandardPrice").nodeValue());
    map.insert("InfantStanderPrice",element.attributes().namedItem("InfantStanderPrice").nodeValue());
    map.insert("DptTerminal",element.attributes().namedItem("DptTerminal").nodeValue());
    map.insert("WorkTime",element.attributes().namedItem("WorkTime").nodeValue());
    map.insert("ChangePnr",element.attributes().namedItem("ChangePnr").nodeValue());
    map.insert("Remark",element.attributes().namedItem("Remark").nodeValue());
    map.insert("PolicyType",element.attributes().namedItem("PolicyType").nodeValue());
    return true;
}
bool policyOp::MatchCommonPolicy(QString DepartureDateTime,QString FlightNumber,QString ResBookDesigCode,QString DepartureAirport,QString ArrivalAirport,QString ReturnPolicyType,QString TripType,QString FlightNumberBack,QString ResBookDesigCodeBack,QString DepartureDateTimeBack)
{
    return this->MatchCommonPolicy(DepartureDateTime.toStdString(),FlightNumber.toStdString(),ResBookDesigCode.toStdString(),DepartureAirport.toStdString(),ArrivalAirport.toStdString(),ReturnPolicyType.toStdString(),TripType.toStdString(),FlightNumberBack.toStdString(),ResBookDesigCode.toStdString(),DepartureDateTimeBack.toStdString(),this->usrName.toStdString(),this->pwd.toStdString(),this->agentCode.toStdString());
}

bool policyOp::MatchCommonPolicy(string DepartureDateTime,string FlightNumber,string ResBookDesigCode,string DepartureAirport,string ArrivalAirport,string ReturnPolicyType,string TripType,string FlightNumberBack,string ResBookDesigCodeBack,string DepartureDateTimeBack,string usrname,string pwd,string agentCode)
{
    _ns1__MatchCommonPolicy req;
    _ns1__MatchCommonPolicyResponse res;
    QString xml = QString("<OTA_AirFareRQ	 AgentCode=\"%1\" AgentUserName=\"%2\" AgentPwd=\"%3\" DepartureDateTime='%4' FlightNumber='%5' ResBookDesigCode='%6' DepartureAirport='%7' ArrivalAirport='%8' ReturnPolicyType='%9'  TripType='%10' FlightNumberBack='%11' ResBookDesigCodeBack='%12' DepartureDateTimeBack='%13'></OTA_AirFareRQ>").arg(agentCode).arg(usrname).arg(pwd).arg(DepartureDateTime).arg(FlightNumber).arg(ResBookDesigCode).arg(DepartureAirport).arg(ArrivalAirport).arg(ReturnPolicyType).arg(TripType).arg(FlightNumberBack).arg(ResBookDesigCodeBack).arg(DepartureDateTimeBack);
    xmldoc = xml.toStdString();
    req.xmlDoc = &xmldoc;
    int callRes = BTproxy->MatchCommonPolicy(&req,&res);
    return this->xmlhandler(callRes,QString().fromStdString(*res.MatchCommonPolicyResult),MatchCommonPolicyVisitor);
}

bool policyOp::MatchCommonPolicyVisitor(QDomElement element)
{
    QMap<QString,QString> map;
    map.insert("Id",element.attributes().namedItem("Id").nodeValue());
    map.insert("Price",element.attributes().namedItem("Price").nodeValue());
    map.insert("AgentPrice",element.attributes().namedItem("AgentPrice").nodeValue());
    map.insert("Commission",element.attributes().namedItem("Commission").nodeValue());
    map.insert("Tax",element.attributes().namedItem("Tax").nodeValue());
    map.insert("YQTax",element.attributes().namedItem("YQTax").nodeValue());
    map.insert("Rate",element.attributes().namedItem("Rate").nodeValue());
    map.insert("MoneyKeep",element.attributes().namedItem("MoneyKeep").nodeValue());
    map.insert("Effdate",element.attributes().namedItem("Effdate").nodeValue());
    map.insert("Expdate",element.attributes().namedItem("Expdate").nodeValue());
    map.insert("IsAutoTicket",element.attributes().namedItem("IsAutoTicket").nodeValue());
    map.insert("IssueTicketSpeed",element.attributes().namedItem("IssueTicketSpeed").nodeValue());
    map.insert("ChangePnr",element.attributes().namedItem("ChangePnr").nodeValue());
    map.insert("ProviderWorkTime",element.attributes().namedItem("ProviderWorkTime").nodeValue());
    map.insert("Remark",element.attributes().namedItem("Remark").nodeValue());
    map.insert("PolicyType",element.attributes().namedItem("PolicyType").nodeValue());
    map.insert("VoidWorkTime",element.attributes().namedItem("VoidWorkTime").nodeValue());
    map.insert("Office",element.attributes().namedItem("ChangePnr").nodeValue());
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
