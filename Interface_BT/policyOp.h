#ifndef POLICY_OP_H
#define POLICY_OP_H

#include <gsoap/soapBaitourServiceSoapProxy.h>
//#include "gsoap/BaitourServiceSoap.nsmap"
#include <QDebug>
#include <QString>
#include <QMap>
#include <QDomDocument>

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

    bool GetAllCommonPolicy(QString, QString);
    bool GetAllCommonPolicy(std::string, std::string, std::string, std::string);
    static bool GetAllCommonPolicyVisitor(QDomElement);
    bool GetAlterCommonPolicy(QString,QString,QString);
    bool GetAlterCommonPolicy(std::string, std::string, std::string,std::string,std::string);
    static bool GetAlterCommonPolicyVisitor(QDomElement);
    bool GetAVPolicy(QString,QString,QString,QString,QString,QString,QString,QString);
    bool GetAVPolicy(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string);
    static bool GetAVPolicyVisitor(QDomElement);
    bool MatchCommonPolicy(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string);
    bool MatchCommonPolicy(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    static bool MatchCommonPolicyVisitor(QDomElement);
    bool GetInvalidationProviders();
    bool GetInvalidationProviders(std::string,std::string,std::string);
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
