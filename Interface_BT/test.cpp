#include <iostream>
#include <cstdio>
#include "gsoap/soapBaitourServiceSoapProxy.h"
#include "gsoap/soapH.h"
#include "gsoap/soapStub.h"
#include "gsoap/BaitourServiceSoap.nsmap"

using namespace std;

int main()
{
	BaitourServiceSoapProxy BTproxy;
	_ns1__GetAlterCommonPolicy req;
    	_ns1__GetAlterCommonPolicyResponse res;
	string usrname = "lhjk";
	string pwd = "lhjk";
	string rQStartDateTime = "2013-11-25T15:20:20.827";
	string tripType = "0";
	string ticketType = "0";
    	req.agentUserName = &usrname;
	req.pwd = &pwd;
    	req.rQStartDateTime = &rQStartDateTime;
    	req.tripType = &tripType;
    	req.ticketType = &ticketType;
    	int callRes = BTproxy.GetAlterCommonPolicy(&req,&res);
	cout << *res.GetAlterCommonPolicyResult << endl;
}
