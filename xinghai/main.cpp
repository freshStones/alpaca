#include <QCoreApplication>
#include <xhhotel.h>
#include "gsoap/BasicHttpBinding_USCOREixinghai.nsmap"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    xhhotel *api;
    api = new xhhotel("13637536854","363753");
    std::wstring str(L"");
    api->getHotelList(str);
    return a.exec();
}
