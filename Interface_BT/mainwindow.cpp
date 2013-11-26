#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDomDocument>
#include <QSettings>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QObject>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->configure();
    this->dataPrepare();
    this->debug();
    ui->progressBar->setRange(0,5000-1);
    ui->progressBar->setValue(0);

    //xmlTest();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::debug()
{
    //this->op->MatchCommonPolicy("2013-11-30T14:25:00","MU5710","Y","PEK","LZO","1","1","","","");
    //this->op->GetAlterCommonPolicy("2013-11-26T00:01:20.827","0","0");
    //this->op->GetAllCommonPolicy("0","0");
}

void MainWindow::configure()
{
    //QString setting("setting.ini");
    //QString setting("/home/daniel/alpaca/Interface_BT/setting.ini");
    QString setting("/Users/xiaosb/Documents/workspace/alpaca/Interface_BT/setting.ini");
    QSettings *configIniRead = new QSettings(setting,QSettings::IniFormat);
    this->op = new policyOp(configIniRead->value("/ACCOUNT/USERNAME").toString(),configIniRead->value("/ACCOUNT/PASSWORD").toString(),configIniRead->value("/AGENT_DESC/AGENTCODE").toString());
}

void MainWindow::dataPrepare()
{
    btDatabase::instance();
    allPolicyModel = new QSqlTableModel;
    allPolicyModel->setTable("policyDescripition");
}
void MainWindow::signalConnection()
{
    connect(this->op,SIGNAL(setProgressBarRange(int)),this,SLOT(slotSetProgressBarRange(int)));
    connect(this->op,SIGNAL(setProgressBarValue(int)),this,SLOT(slotSetProgressBarValue(int)));
}

void MainWindow::on_pushButton_clicked()
{
    //this->op->GetAlterCommonPolicy("2013-11-26T00:01:20.827","0","0");
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

void MainWindow::on_queryButton_clicked()
{
    QString filter("departureCityCodes like \"\%" + ui->dep->text() + "\%\""+"and arrivalCityCodes like \"\%" + ui->arr->text() + "\%\"" + " and supplierTTLofficeAccount like \"\%" + ui->officeNo->text() + "\"");
    filter += " and airlinecode like \"\%" + ui->companyCode->text() + "\" and policyStatus = 1";
    if (ui->pnrCheck->checkState()==Qt::Checked)
        filter += " and shouldChangePNR = 1";
    if (ui->rateGtCheck->checkState()==Qt::Checked)
        filter += " and rebateRate > " + ui->rateGt->text();
    if (ui->rateLtCheck->checkState()==Qt::Checked)
        filter += " and rebateRate < " + ui->rateLt->text();
    allPolicyModel->setFilter(filter);
    allPolicyModel->select();
    ui->allPolicyTableView->setModel(allPolicyModel);
    ui->allPolicyTableView->setColumnHidden(0,true);
    ui->allPolicyTableView->setColumnHidden(1,true);
}

void MainWindow::on_dumpButton_clicked()
{
    QString airlineCode,applicableFlight,rebateRate;
    double price = 0;
    QString moneyKeep = "-10",CertificateID = "0";
    QString insert = "", value = "";
    QString flightRestriction="所有";
    for(int i = 0; i < allPolicyModel->rowCount(); ++i){
        flightRestriction="所有";
        airlineCode = allPolicyModel->record(i).value("airlineCode").toString();
        rebateRate = QString::number(100*(allPolicyModel->record(i).value("rebateRate").toDouble()),'f',2);
        applicableFlight = allPolicyModel->record(i).value("applicableFlight").toString();
        if(applicableFlight != ""){
            qDebug() << "适用" << endl;
            flightRestriction = "适用";
            QStringList row = applicableFlight.split(',');
            applicableFlight = "";
            qDebug() << row.count() << " ";
            for(int i = 0; i < row.count()-1;i++){
               applicableFlight +=  airlineCode + QString::number(row.at(i).toLong(),10)+",";
            }
            applicableFlight +=  airlineCode + QString::number(row.at(row.count()-1).toLong(),10);
        }

        value = "'" + airlineCode + "','" + allPolicyModel->record(i).value("policyCode").toString() + "','" + allPolicyModel->record(i).value("departureCityCodes").toString() + "','" + allPolicyModel->record(i).value("arrivalCityCodes").toString() + "','" +  flightRestriction + "','" + applicableFlight + "','" + allPolicyModel->record(i).value("timetableRestriction").toString() + "','"
                + allPolicyModel->record(i).value("applicableSpaceCode").toString() + "',default,'"+ price + "','" + rebateRate + "','"+ moneyKeep + "','" + allPolicyModel->record(i).value("ticketingDateLimitStart").toString() + "','" + allPolicyModel->record(i).value("ticketingDateLimitEnd").toString() + "','" +
                allPolicyModel->record(i).value("ticketingDateLimitStart").toString() + "','" + allPolicyModel->record(i).value("ticketingDateLimitEnd").toString() + "',default,'" + allPolicyModel->record(i).value("ticketingDateLimitStart").toString() + "','" + allPolicyModel->record(i).value("ticketingDateLimitEnd").toString() + "',default,default,default,default,default,'',default,default,default,default,default,'"
                +CertificateID + "',default,default,''";
        insert = "insert into qunarTable values(" + value + ");";
        btDatabase::instance()->execSQL(insert);
    }
}
