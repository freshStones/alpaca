#include "policyOp.h"
#include "gsoap/BaitourServiceSoap.nsmap"
#include <QTime>
#include <QDate>

QString policyOp::sqlCollection = "";

policyOp::policyOp(QString _usrName, QString _pwd, QString _agentcode)
{
    BTproxy = new BaitourServiceSoapProxy();
    usrName = _usrName;
    pwd = _pwd;
    agentCode = _agentcode;
    qDebug() << usrName << pwd << agentCode << endl;
}

void policyOp::showDebugMsg(QString msg)
{
    qDebug() << msg << endl;
}
void policyOp::showmap(QMap<QString, QString> map)
{
    QMap<QString,QString>::const_iterator i;
    for( i = map.constBegin(); i != map.constEnd(); ++i)
           qDebug() << i.key() <<": " << i.value()<<endl;
}
QString policyOp::genQuery(QString table, QMap<QString,QString> map)
{
    QString keys(""),values("");
    QMap<QString,QString>::const_iterator i;
    i = map.constBegin();
    keys += i.key();
    values+= "'" + i.value() + "'";
    i++;
    for( ; i!=map.constEnd(); ++i)
    {
        keys = keys + "," + i.key();
        values = values + "," + "'" + i.value() + "'";
    }
    return QString("replace into %1(%2) values(%3);\n").arg(table).arg(keys).arg(values);
}

bool policyOp::xmlhandler(int callRes,QString xml,bool (*visitor)(QDomElement))
{
    if(callRes == SOAP_OK){
        QDomDocument doc;
        QString errorMSG;
        int errLine = 0, errCol = 0;
        //showDebugMsg(xml);
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
        emit setProgressBarRange(root.childNodes().count());
        QDomElement element = root.firstChildElement();
        int itemCount = 0;
        while(!element.isNull()){
            itemCount++;
            (*visitor)(element);
            emit setProgressBarValue(itemCount);
            element = element.nextSiblingElement();       
        }
        btDatabase::instance()->batchOperation(sqlCollection);
        btDatabase::instance()->commitOperation();
        sqlCollection = "";
    }
    else{
        showDebugMsg(QString("GetAllCommonPolicy call failed. Error code: %1").arg(callRes));
    }
    return true;
}
bool policyOp::GetAllCommonPolicy(QString tripType,QString ticketType)
{
    QString dt;
    QString date;
    QString time;
    date = QDate().currentDate().toString("yyyy-MM-dd");
    time = QTime().currentTime().toString("hh:mm:ss");
    dt = date + "T" + time;
    lasttime = dt;
    return this->GetAllCommonPolicy(tripType.toStdWString(), ticketType.toStdWString(), this->usrName.toStdWString(),this->pwd.toStdWString());
}

bool policyOp::GetAllCommonPolicy(std::wstring tripType, std::wstring ticketType, std::wstring username, std::wstring pwd)
{
    _ns1__GetAllCommonPolicy req;
    _ns1__GetAllCommonPolicyResponse res;
    req.tripType = &tripType;
    req.ticketType = &ticketType;
    req.agentUserName = &username;
    req.pwd = &pwd;
    int callRes = BTproxy->GetAllCommonPolicy(&req, &res);
    return this->xmlhandler(callRes,QString().fromStdWString(*res.GetAllCommonPolicyResult),GetAlterCommonPolicyVisitor);
}

bool policyOp::GetAllCommonPolicyVisitor(QDomElement element)
{
    return policyOp::GetAlterCommonPolicyVisitor(element);
}

bool policyOp::GetAlterCommonPolicy(QString rQStartDateTime, QString tripType, QString ticketType)
{
    return this->GetAlterCommonPolicy(rQStartDateTime.toStdWString(),tripType.toStdWString(),ticketType.toStdWString(),this->usrName.toStdWString(),this->pwd.toStdWString());
}

bool policyOp::GetAlterCommonPolicy(std::wstring rQStartDateTime,std::wstring tripType,std::wstring ticketType,std::wstring usrname,std::wstring pwd)
{
    //qDebug()<<QString().fromStdString(rQStartDateTime)<<QString().fromStdString(tripType)<<QString().fromStdString(usrname)<<endl;
    _ns1__GetAlterCommonPolicy req;
    _ns1__GetAlterCommonPolicyResponse res;
    req.agentUserName = &usrname;
    req.pwd = &pwd;
    req.rQStartDateTime = &rQStartDateTime;
    req.tripType = &tripType;
    req.ticketType = &ticketType;
    int callRes = BTproxy ->GetAlterCommonPolicy(&req,&res);
    this->xmlhandler(callRes,QString().fromStdWString(*res.GetAlterCommonPolicyResult),GetAlterCommonPolicyVisitor);
    return true;
}
bool policyOp::GetAlterCommonPolicyVisitor(QDomElement element)
{
    QStringList qsl = element.text().split("|");

    QMap<QString,QString> map;
    map.insert("policy_uuid",element.attributes().namedItem("Id").nodeValue());
    map.insert("policyStatus",element.attributes().namedItem("State").nodeValue());
    map.insert("shouldChangePNR",element.attributes().namedItem("IsChangePnr").nodeValue());
    map.insert("departureCityCodes",qsl.at(0));
    map.insert("arrivalCityCodes",qsl.at((1)));
    map.insert("airlineCode",qsl.at(2));
    map.insert("flightType",qsl.at(3));
    map.insert("applicableFlight",qsl.at(4));
    map.insert("inapplicableFlight",qsl.at(5));
    map.insert("timetableRestriction",qsl.at(6));
    map.insert("ticketType",qsl.at(7));
    map.insert("applicableSpaceCode",qsl.at(8));
    map.insert("rebateRate",qsl.at(9));
    map.insert("ticketingDateLimitStart",qsl.at(10).split(",").at(0));
    map.insert("ticketingDateLimitEnd",qsl.at(10).split(",").at(1));
    map.insert("supplierTTLofficeAccount",qsl.at(12));
    map.insert("policyEntryDateTime",qsl.at(13));
    map.insert("policyModifyDatetime",qsl.at(14));
    map.insert("supplierCode",qsl.at(15));
    map.insert("memo",qsl.at(16));
    map.insert("autoTicketingEnabled",qsl.at(17));  //百拓的文档写错了，这里应该有
    sqlCollection += genQuery("policyDescripition", map);
    if(sqlCollection.count(";") == 1000 )
    {
        btDatabase::instance()->batchOperation(sqlCollection);
        sqlCollection = "";
    }
    //qDebug() << sqlCollection.count(";") << endl;
    return true;
}
bool policyOp::GetAVPolicy(QString Type,QString OrderSrc,QString DptAirport,QString ArrAirport,QString TakeOffDate,QString Cabin,QString FlightNum,QString avinfo)
{
    _ns1__GetAVPolicy req;
    _ns1__GetAVPolicyResponse res;
    QString xml = QString("<FlightSearch AgentCode=\"%1\" AgentUserName=\"%2\" AgentPwd=\"%3\" ><AV  Type=\"%4\" OrderSrc=\"%5\"  DptAirport=\"%6\"  ArrAirport=\"%7\"  TakeOffDate=\"%8\" Cabin=\"%9\"  FlightNum=\"%10\">%11</AV></FlightSearch>").arg(agentCode).arg(usrName).arg(pwd).arg(Type).arg(OrderSrc).arg(DptAirport).arg(ArrAirport).arg(TakeOffDate).arg(Cabin).arg(FlightNum).arg(avinfo);
    std::wstring xmldoc = xml.toStdWString();
    req.xmlDoc = &xmldoc;
    int callRes = BTproxy ->GetAVPolicy(&req,&res);
    return this->xmlhandler(callRes,QString().fromStdWString(*res.GetAVPolicyResult),GetAVPolicyVisitor);
}
bool policyOp::GetAVPolicyVisitor(QDomElement element)
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
    _ns1__MatchCommonPolicy req;
    _ns1__MatchCommonPolicyResponse res;
    QString xml = QString("<OTA_AirFareRQ	 AgentCode=\"%1\" AgentUserName=\"%2\" AgentPwd=\"%3\" DepartureDateTime='%4' FlightNumber='%5' ResBookDesigCode='%6' DepartureAirport='%7' ArrivalAirport='%8' ReturnPolicyType='%9'  TripType='%10' FlightNumberBack='%11' ResBookDesigCodeBack='%12' DepartureDateTimeBack='%13'></OTA_AirFareRQ>").arg(agentCode).arg(usrName).arg(pwd).arg(DepartureDateTime).arg(FlightNumber).arg(ResBookDesigCode).arg(DepartureAirport).arg(ArrivalAirport).arg(ReturnPolicyType).arg(TripType).arg(FlightNumberBack).arg(ResBookDesigCodeBack).arg(DepartureDateTimeBack);
    std::wstring xmldoc = xml.toStdWString();
    req.xmlDoc = &xmldoc;
    int callRes = BTproxy->MatchCommonPolicy(&req,&res);
    return this->xmlhandler(callRes,QString().fromStdWString(*res.MatchCommonPolicyResult),MatchCommonPolicyVisitor);
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
    policyOp::showmap(map);
    return true;
}
bool policyOp::GetInvalidationProviders()
{
    return this->GetInvalidationProviders(this->usrName.toStdWString(),this->pwd.toStdWString(),this->agentCode.toStdWString());
}
bool policyOp::GetInvalidationProviders(std::wstring usrname,std::wstring pwd,std::wstring agentCode)
{
    _ns1__GetInvalidationProviders req;
    _ns1__GetInvalidationProvidersResponse res;
    req.AgentCode = &agentCode;
    req.AgentPwd = &pwd;
    req.AgentUserName = &usrname;
    int callRes = BTproxy->GetInvalidationProviders(&req,&res);
    return this->xmlhandler(callRes,QString().fromStdWString(*res.GetInvalidationProvidersResult),GetInvalidationProvidersVisitor);
}
bool policyOp::GetInvalidationProvidersVisitor(QDomElement element)
{

}
void policyOp::alter()
{
    QString dt;
    QString date;
    QString time;
    date = QDate().currentDate().toString("yyyy-MM-dd");
    time = QTime().currentTime().toString("hh:mm:ss");
    dt = date + "T" + time;
    qDebug()<<"alter:"<<dt<<endl;
    GetAlterCommonPolicy(lasttime,"0","0");
    lasttime = dt;
}
