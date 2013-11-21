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

    bool op_GetAllCommonPolicy();
    bool op_GetAllCommonPolicyZIP();
    bool op_GetAlterCommonPolicy();
    bool op_GetAVPolicy();
    bool op_GetChangeFlightDate();
    bool op_GetDomesticMatchNormalZRateByID();
    bool op_GetInvalidationProviders();
    bool op_GetOrderInfo();
    bool op_DetailCreateOrder();
    bool op_MatchCommonPolicy();
    bool op_RefundOrder();
    bool op_RTCreateOrder();

private:
    BaitourServiceSoapProxy* BTproxy;

};

#endif // POLICY_OP_H
