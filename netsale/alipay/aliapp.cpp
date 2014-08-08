#include "aliapp.h"

aliapp::aliapp()
{
}
void aliapp::execute(QMap<QString, QString> map)
{
    QMap<QString,QString>::Iterator it = map.begin();
    QString url = QString("http://xxx.com:6350/alidz.do?%1=%2").arg(it.key()).arg(it.value());
    for	(; it!=map.end(); it++)
    {
        url+= QString("&%1=%2").arg(it.key()).arg(it.value());
    }
    QNetworkRequest req;
    req.setUrl(QUrl(url));
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *rep = manager->get(req);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    //connect(rep,SIGNAL(readyRead()),this,SLOT(on_readyRead()));
}

void aliapp::replyFinished(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    reply->deleteLater();
    qDebug()<<data;
}

void jsonDecoder(QString data)
{
    QJsonParseError jsonErr;
    QJsonDocument json = QJsonDocument::fromJson(data.toLatin1(),&jsonErr);
    if (jsonErr.error == QJsonParseError::NoError)
    {
        if (json.isObject())
        {
            QJsonObject obj = json.object();
            if (obj.contains("error"))
            {
                qDebug() << "error:" << obj["error"];
            }
            else
            {
                QJsonArray jarray = obj["invlist"].toArray();
                for (int row = 0; row < jarray.size(); row++)
                {
                    qDebug() << "====Row[" << row << "] Start===================";
                    QJsonObject jobj = jarray[row].toObject();
                    for (QJsonObject::Iterator it = jobj.begin();
                         it != jobj.end(); it++)
                    {
                        qDebug() << it.key() << " => " << it.value();
                    }
                }
            }
        }
        else
        {
            qDebug() << "error, shoud json object";
        }
    }
    else
    {
        qDebug() << "error:" << jsonErr.errorString();
    }
}
