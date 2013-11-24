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

    bool GetAllCommonPolicy(QString, QString);
    bool GetAllCommonPolicy(std::string, std::string, std::string, std::string);
    //bool GetAllCommonPolicyZIP();
    //bool GetAlterCommonPolicy(std::string, std::string, std::string);
    //bool GetAVPolicy(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string);
    //bool GetChangeFlightDate();
    //bool GetDomesticMatchNormalZRateByID();
    //bool GetInvalidationProviders();
    //bool GetOrderInfo();
    //bool DetailCreateOrder();
    //bool MatchCommonPolicy();
    //bool RefundOrder();
    //bool RTCreateOrder();
    bool showDebugMsg(QString);
private:
    BaitourServiceSoapProxy* BTproxy;

};

#endif // POLICY_OP_H
