#include<iostream>
#include<cstdio>
#include<string>
#include "gsoap/soapBaitourServiceSoapProxy.h"
#include "gsoap/BaitourServiceSoap.nsmap"
#include "gsoap/soapStub.h"
#include "gsoap/soapH.h"

using namespace std;
int main(int argc, const char *argv[])
{
	BaitourServiceSoapProxy proxy;
	_ns1__GetAllCommonPolicy ns1__GetAllCommonPolicy;
	string a = "0",b = "0",c = "lhjk",d = "lhjk";
	ns1__GetAllCommonPolicy.tripType = &a;
	ns1__GetAllCommonPolicy.ticketType = &b;
	ns1__GetAllCommonPolicy.agentUserName = &c;
	ns1__GetAllCommonPolicy.pwd = &d;
	_ns1__GetAllCommonPolicyResponse ns1__GetAllCommonPolicyResponse;
	proxy.GetAllCommonPolicy(&ns1__GetAllCommonPolicy,&ns1__GetAllCommonPolicyResponse);
	cout << *(ns1__GetAllCommonPolicyResponse.GetAllCommonPolicyResult);
	return 0;
}
