#include "ota_xmlhttp.h"

OTA_XMLHTTP::OTA_XMLHTTP()
{
}

QString OTA_XMLHTTP::GetResponse(QString requestXML)
{
    requestXML = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><OTA_AirDetailsRQ><POS><Source PseudoCityCode=\"HAK295\" /></POS><AirDetail DepartureDate=\"2014-06-10\" FlightNumber=\"1831\" Cabin=\"Y\"><Airline Code=\"CA\" /><DepartureAirport LocationCode=\"PEK\" /><ArrivalAirport LocationCode=\"SHA\" /></AirDetail></OTA_AirDetailsRQ>";
    requestXML = requestXML.remove("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");

    QString accquiredXML = "";
    QByteArray content = requestXML.toLatin1();
    QString usr_pwd = this->usr + ":" + this->pwd;
    QByteArray authBytes = usr_pwd.toUtf8().toBase64();

    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest req;

    req.setUrl(QUrl("http://espeed.travelsky.com/develop/xml/AirDetails"));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    req.setRawHeader("Authorization", "Basic " + authBytes);
    req.setHeader(QNetworkRequest::ContentLengthHeader,content.length());
    QNetworkReply *rtn = networkManager->post(req,content);

//    QObject::connect(rtn, SIGNAL(readyRead()), this, SLOT(replyFinished(QNetworkReply*)));
}

void OTA_XMLHTTP::replyFinished(QNetworkReply * rtn)
{

}
