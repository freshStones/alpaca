#include "policy_op.h"
#include "gsoap/BaitourServiceSoap.nsmap"


policy_op::policy_op()
{
    BTproxy = new BaitourServiceSoapProxy();
}

bool policy_op::GetAllCommonPolicy()
{

    _ns1__GetAllCommonPolicy req;
    _ns1__GetAllCommonPolicyResponse res;

    std::string tripType = "0", ticketType = "0";
    std::string agentUserName = "lhjk", pwd = "lhjk";
    req.tripType = &tripType;
    req.ticketType = &ticketType;
    req.agentUserName = &agentUserName;
    req.pwd = &pwd;

    BTproxy->GetAllCommonPolicy(&req, &res);

    qDebug() << res.GetAllCommonPolicyResult << endl;
    return true;
}

bool policy_op::GetAllCommonPolicyZIP()
{

}
bool policy_op::GetAlterCommonPolicy();
bool policy_op::GetAVPolicy();
bool policy_op::GetChangeFlightDate();
bool policy_op::GetDomesticMatchNormalZRateByID();
bool policy_op::GetInvalidationProviders();
bool policy_op::GetOrderInfo();
bool policy_op::DetailCreateOrder();
bool policy_op::MatchCommonPolicy();
bool policy_op::RefundOrder();
bool policy_op::RTCreateOrder();
