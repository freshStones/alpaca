//****************************************************************************************************************
//*     This Qt based program is producted by Team 2022, with Hainan Langhua Business Travel Service Co. Ltd.    *
//*                                    Generated in: 11/28/2013                                                  *
//*                                 Members: joker, zghember, god miao                                           *
//*                          Partner: Hainan Langhua Business Travel Service Co. Ltd.                            *
//*                                      "Winter in PKU is beautiful!"                                           *
//****************************************************************************************************************

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");
    //避免中文乱码
#ifdef Q_OS_WIN32
    QTextCodec *codec = QTextCodec::codecForName("System");
#else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
#endif

    QTextCodec::setCodecForLocale(codec);

    //避免多个程序实例
#ifdef Q_OS_WIN
    QSharedMemory shrMemo;
    shrMemo.setKey("LHOneInstanceLock");
    if(!shrMemo.create(1))
    {
        QMessageBox::warning(NULL,QObject::tr("Warning"),QObject::tr("已经启动本程序的另一个实例！"),QMessageBox::Ok);
        return -1;
    }
#endif
    QIcon icon;
    icon.addFile(QStringLiteral(":/images/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
    //a.setWindowIcon(icon);

    MainWindow w;
    return a.exec();
}
