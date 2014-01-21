#ifndef SYSLOG_H
#define SYSLOG_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>

class sysLog
{
public:
    sysLog(QString);
    bool writelog(QString);
private:
    QString qs_logfile_path;
    QFile *qf_logfile;
    QTextStream *qts_logOutput;

};

#endif // SYSLOG_H
