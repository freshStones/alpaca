#include<iostream>
#include<cstdio>
#include<string>
#include "gsoap/soapBaitourServiceSoapProxy.h"
#include "gsoap/BaitourServiceSoap.nsmap"

using namespace std;
int main(int argc, const char *argv[])
{
	BaitourServiceSoapProxy proxy;
	_ns1__GetAllCommonPolicy ns1__GetAllCommonPolicy;
	_ns1__GetAllCommonPolicyResponse ns1__GetAllCommonPolicyResponse;
	proxy.GetAllCommonPolicy(ns1__GetAllCommonPolicy,ns1__GetAllCommonPolicyResponse);
	print ns1__GetAllCommonPolicyResponse.
	return 0;
}
