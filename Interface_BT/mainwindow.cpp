#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QString>
#include <QDebug>
#include <QDomDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //BTtest();
    xmlTest();
}

void MainWindow::BTtest(){
    policy_op p;
    p.GetAllCommonPolicy();
}

void MainWindow::xmlTest(){
    char fileName[100] = "/home/daniel/Desktop/201311200359065980000.xml";

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << QString("File %1 open failed!").arg(fileName) << endl;
    }
    else{
        qDebug() << QString("File %1 open succeeded!").arg(fileName) << endl;

        QDomDocument doc;
        QString errorMSG;
        int errLine = 0, errCol = 0;
        if( !doc.setContent(&file, false, &errorMSG, &errLine, &errCol) ) {
            qDebug() << QString("Parse file failed at line %1 column %2, error: %3 !").arg(errLine).arg(errCol).arg(errorMSG) << endl;
            return;
        }
        else{
            qDebug() << "Parse Succeeded!" << endl;
        }

        if(doc.isNull()){
            qDebug() << "Document is null!" << endl;
            return;
        }

        QDomElement root = doc.documentElement();

        QDomElement element = root.firstChildElement();
        int count  = 0;
        while(!element.isNull()){
            qDebug() << element.nodeName() << endl;
            element = element.nextSiblingElement();
            count++;
        }
        qDebug() << count << endl;

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
