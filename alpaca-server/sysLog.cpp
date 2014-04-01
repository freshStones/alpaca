#include "sysLog.h"

sysLog::sysLog(QString path)
{
    qs_logfile_path = path;

    this->writelog(QString("Alpaca server log loaded. Log file path: %1").arg(qs_logfile_path));

    qDebug() << "log file loaded.";
}

bool sysLog::writelog(QString qs_logLine){

    qf_logfile = new QFile(qs_logfile_path);

    if(!qf_logfile->open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "server log file open failed!";
        return false;
    }
    qts_logOutput = new QTextStream(qf_logfile);

    *qts_logOutput << qs_logLine << endl;

    qf_logfile->close();
    qts_logOutput->~QTextStream();
    qf_logfile->~QFile();

    return true;
}
