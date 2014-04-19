#include <QCoreApplication>
#include <xhhotel.h>
#include "gsoap/BasicHttpBinding_USCOREixinghai.nsmap"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    xhhotel *api;
    api = new xhhotel("430","e31977d6d0262a45");
    std::wstring str(L"");
    //api->getHotelList(str);
    //api->getHotelInfo(1);
    api->getHotelPrice(1,L"",L"2014-4-19",L"2014-4-30");
    return a.exec();
}
