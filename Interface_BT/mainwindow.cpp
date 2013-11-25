#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDomDocument>
#include <QSettings>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //btDatabase::instance();
    //allPolicyModel = new QSqlTableModel;
    //allPolicyModel->setTable("policyDescripition");
    //allPolicyModel->select();
    //ui->allPolicyTableView->setModel(allPolicyModel);

    ui->progressBar->setRange(0,5000-1);
    ui->progressBar->setValue(0);

    //xmlTest();

    QSettings *configIniRead = new QSettings("/home/daniel/alpaca/Interface_BT/setting.ini",QSettings::IniFormat);
    this->op = new policyOp(configIniRead->value("/ACCOUNT/USERNAME").toString(),configIniRead->value("/ACCOUNT/PASSWORD").toString(),configIniRead->value("/AGENT_DESC/AGENTCODE").toString());

    connect(this->op,SIGNAL(setProgressBarRange(int)),this,SLOT(slotSetProgressBarRange(int)));
    connect(this->op,SIGNAL(setProgressBarValue(int)),this,SLOT(slotSetProgressBarValue(int)));
    //QSqlDatabase::database().transaction();
    //this->op->GetAlterCommonPolicy("2013-11-26T01:13:20.827","0","0");
    //QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    //QSqlDatabase::database().commit();
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
        this->op->showDebugMsg(element.nodeName());
        this->op->showDebugMsg(QString("%1").arg(element.attributes().namedItem("Id").nodeValue()));

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //this->op->GetAlterCommonPolicy("2013-11-26T01:01:20.827","0","0");
    this->op->GetAllCommonPolicy("0","0");
}

void MainWindow::slotSetProgressBarRange(int x){
    if(x != 0 ) ui->progressBar->setRange(0,x);
    ui->label->setText(QString("%1 Items in total, 0 processed.").arg(x));
}

void MainWindow::slotSetProgressBarValue(int x){
    ui->progressBar->setValue(x);
    QString str = ui->label->text();
    int i = str.indexOf(", ") + 2;
    int j = str.indexOf("processed") - 1;
    ui->label->setText(str.replace(i,j-i,QString("%1").arg(x)));
}
