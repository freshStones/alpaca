#ifndef POLICY_OP_H
#define POLICY_OP_H

#include <gsoap/soapBaitourServiceSoapProxy.h>
//#include "gsoap/BaitourServiceSoap.nsmap"
#include <QDebug>
#include <QString>
#include <QMap>
#include <QDomDocument>

#include "btdatabase.h"

namespace ns1 {
class policyOp;
}
class policyOp
{
private:
    QString usrName, pwd, agentCode;

public:
    policyOp(QString, QString, QString);
    bool xmlhandler(int,QString,bool (*visitor)(QDomElement));
    static void showmap(QMap<QString,QString>);
    bool GetAllCommonPolicy(QString, QString);
    bool GetAllCommonPolicy(std::wstring, std::wstring, std::wstring, std::wstring);
    static bool GetAllCommonPolicyVisitor(QDomElement);
    bool GetAlterCommonPolicy(QString,QString,QString);
    bool GetAlterCommonPolicy(std::wstring, std::wstring, std::wstring,std::wstring,std::wstring);
    static bool GetAlterCommonPolicyVisitor(QDomElement);
    bool GetAVPolicy(QString,QString,QString,QString,QString,QString,QString,QString);
    static bool GetAVPolicyVisitor(QDomElement);
    bool MatchCommonPolicy(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    static bool MatchCommonPolicyVisitor(QDomElement);
    bool GetInvalidationProviders();
    bool GetInvalidationProviders(std::wstring,std::wstring,std::wstring);
    static bool GetInvalidationProvidersVisitor(QDomElement);
    //bool GetAllCommonPolicyZIP();
    //bool GetChangeFlightDate();
    //bool GetDomesticMatchNormalZRateByID();
    //bool GetOrderInfo();
    //bool DetailCreateOrder();
    //bool RefundOrder();
    //bool RTCreateOrder();
    void showDebugMsg(QString);
private:
    BaitourServiceSoapProxy* BTproxy;

};

#endif // POLICY_OP_H
