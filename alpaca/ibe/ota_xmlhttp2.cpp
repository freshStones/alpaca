#include "ota_xmlhttp2.h"

OTA_XMLHTTP2::OTA_XMLHTTP2(QObject *parent) :
    QObject(parent)
{
    this->usr = "hnlh";
    this->pwd = "123456";
    this->url = QUrl("http://espeed.travelsky.com/develop/xml/AirBrief");
    this->_qhttp = new QHttp(this);
    connect(_qhttp, SIGNAL(done(bool)), this, SLOT(done(bool)));
}

QString OTA_XMLHTTP2::GetResponse(QString requestXML)
{
//    _qhttp->setHost("http://espeed.travelsky.com/develop/xml/AirBrief");
    _rssfile = new QFile();
    _rssfile->setFileName("./new.xml");
    _rssfile->open(QIODevice::WriteOnly | QIODevice::Text);

    //generate request xml
    QFile xml("/home/daniel/ibe/IBExml/FlightInquiry/AirBrief/AirBrief/OTA_AirBriefRQ.xml");
    if(!xml.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "OTA xml file cannot be opened.";
    }
    else{
        QTextStream in(&xml);
        requestXML = in.readAll();
//        qDebug() << requestXML;
    }
    requestXML = requestXML.remove("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    QByteArray inputStr = requestXML.toAscii();
//    QHttpRequestHeader header("POST","/develop/xml/AirBrief");
    QHttpRequestHeader header("POST",url.path());
    header.setValue("Content-Type", "application/x-www-form-urlencoded");
    header.setValue("Host", url.host());
//    header.setContentLength(inputStr.length());/*bad move*/
    _qhttp->setHost(url.host());

    QByteArray authBytes = (this->usr + ":" + this->pwd).toUtf8().toBase64();
    header.setValue("Authorization", "Basic " + authBytes);

    int requestID = _qhttp->request(header, inputStr, _rssfile);
    qDebug() << inputStr;
    _qhttp->close();
}

void OTA_XMLHTTP2::done(bool error)
{
    if(error)
        qDebug() << "Error: "<< _qhttp->errorString();
    else
    {
        qDebug() << "Done!";
        _rssfile->close();
    }

    emit finished();
}
