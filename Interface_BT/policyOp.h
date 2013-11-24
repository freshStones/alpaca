#ifndef POLICY_OP_H
#define POLICY_OP_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <gsoap/soapBaitourServiceSoapProxy.h>
//#include "gsoap/BaitourServiceSoap.nsmap"
#include <QDebug>
#include <QString>
#include <QMap>

namespace ns1 {
class policyOp;
}
class policyOp
{
    std::string username,pwd,agentCode;
public:
    policyOp();

    bool GetAllCommonPolicy(std::string, std::string);
    bool GetAllCommonPolicyZIP();
    bool GetAlterCommonPolicy(std::string, std::string, std::string);
    bool GetAVPolicy(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string);
    bool GetChangeFlightDate();
    bool GetDomesticMatchNormalZRateByID();
    bool GetInvalidationProviders();
    bool GetOrderInfo();
    bool DetailCreateOrder();
    bool MatchCommonPolicy();
    bool RefundOrder();
    bool RTCreateOrder();
    bool showDebugMsg(std::string);
private:
    BaitourServiceSoapProxy* BTproxy;

};

#endif // POLICY_OP_H
