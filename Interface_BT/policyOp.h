#ifndef POLICY_OP_H
#define POLICY_OP_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <gsoap/soapBaitourServiceSoapProxy.h>
//#include "gsoap/BaitourServiceSoap.nsmap"
#include <QDebug>
#include <QString>
#include <Qmap>

namespace ns1 {
class policyOp;
}
class policyOp
{
    std::string username,pwd,agentCode;
public:
    policyOp();

    bool GetAllCommonPolicy();
    bool GetAllCommonPolicyZIP();
    bool GetAlterCommonPolicy();
    bool GetAVPolicy();
    bool GetChangeFlightDate();
    bool GetDomesticMatchNormalZRateByID();
    bool GetInvalidationProviders();
    bool GetOrderInfo();
    bool DetailCreateOrder();
    bool MatchCommonPolicy();
    bool RefundOrder();
    bool RTCreateOrder();
    bool debugMsg(std::string);
private:
    BaitourServiceSoapProxy* BTproxy;

};

#endif // POLICY_OP_H
