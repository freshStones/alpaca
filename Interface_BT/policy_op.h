#ifndef POLICY_OP_H
#define POLICY_OP_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <gsoap/soapBaitourServiceSoapProxy.h>
//#include "gsoap/BaitourServiceSoap.nsmap"
#include <QDebug>

namespace ns1 {
class policy_op;
}
class policy_op
{
public:
    policy_op();

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

private:
    BaitourServiceSoapProxy* BTproxy;

};

#endif // POLICY_OP_H
