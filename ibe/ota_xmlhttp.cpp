#include "ota_xmlhttp.h"

OTA_XMLHTTP::OTA_XMLHTTP(QObject *parent) :
    QObject(parent)
{
    usr = "hnlh";
    pwd = "123456";
    _postManager = new QNetworkAccessManager(this);
    connect(_postManager,SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

OTA_XMLHTTP::~OTA_XMLHTTP()
{
    _reply->deleteLater();
    _postManager->deleteLater();
}

void OTA_XMLHTTP::setErrorMessage(const QString &msg)
{
    qDebug() << msg;
    _errMsg = msg;
}

const QString& OTA_XMLHTTP::getLastErrorMessage()
{
    return _errMsg;
}

QString OTA_XMLHTTP::GetResponse(QString requestXML)
{
    requestXML = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><OTA_AirDetailsRQ><POS><Source PseudoCityCode=\"HAK295\" /></POS><AirDetail DepartureDate=\"2014-06-10\" FlightNumber=\"1831\" Cabin=\"Y\"><Airline Code=\"CA\" /><DepartureAirport LocationCode=\"PEK\" /><ArrivalAirport LocationCode=\"SHA\" /></AirDetail></OTA_AirDetailsRQ>";
    requestXML = requestXML.remove("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
//    qDebug() << requestXML;

    //generate request xml
    QFile xml("/home/daniel/ibe/IBExml/FlightInquiry/AirBrief/AirBrief/OTA_AirBriefRQ.xml");
    if(!xml.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "xml file cannot be opened.";
    }
    else{
        QTextStream in(&xml);
        requestXML = in.readAll();
//        qDebug() << requestXML;
    }

    //generate http post request
    try{
        _request = new QNetworkRequest();

        //set server url
        _request->setUrl(QUrl("http://espeed.travelsky.com/develop/xml/AirBrief"));

        /*set request header*/
        QByteArray content = requestXML.toLatin1();
        _request->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        _request->setHeader(QNetworkRequest::ContentLengthHeader,content.length());

        QByteArray authBytes = (this->usr + ":" + this->pwd).toUtf8().toBase64();
        _request->setRawHeader("Authorization", "Basic " + authBytes);

        _reply = _postManager->post(*_request,content);
        connect(_reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
        connect(_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
    }
    catch(...){
        qDebug() << "exception here";
    }

    qDebug() << _reply->request().rawHeaderList() << _reply->request().rawHeader("Content-Type")
             << _reply->request().rawHeader("Authorization") << _reply->request().rawHeader("Content-Length");

}

void OTA_XMLHTTP::replyFinished(QNetworkReply * rtn)
{
    qDebug() << _reply->readAll();
}

void OTA_XMLHTTP::slotError(QNetworkReply::NetworkError errorCode) /*handle error*/
{
    qDebug() << "error:" << errorCode;
    setErrorMessage(QString("Error:NetworkError code:%1").arg(errorCode));
}

void OTA_XMLHTTP::slotReadyRead()
{
    qDebug() << _reply->readAll();
}

void OTA_XMLHTTP::handleTimeOut()
{
}
