#include "policy_op.h"
#include "gsoap/BaitourServiceSoap.nsmap"


policy_op::policy_op()
{
    BTproxy = new BaitourServiceSoapProxy();
}

bool policy_op::op_GetAllCommonPolicy()
{

    _ns1__GetAllCommonPolicy ns1__GetAllCommonPolicy;
    _ns1__GetAllCommonPolicyResponse ns1__GetAllCommonPolicyResponse;

    std::string tripType = "0", ticketType = "0";
    std::string agentUserName = "lhjk", pwd = "lhjk";
    ns1__GetAllCommonPolicy.tripType = &tripType;
    ns1__GetAllCommonPolicy.ticketType = &ticketType;
    ns1__GetAllCommonPolicy.agentUserName = &agentUserName;
    ns1__GetAllCommonPolicy.pwd = &pwd;

    BTproxy->GetAllCommonPolicy(&ns1__GetAllCommonPolicy, &ns1__GetAllCommonPolicyResponse);

    qDebug() << ns1__GetAllCommonPolicyResponse.GetAllCommonPolicyResult->data() << endl;
    return true;
}

