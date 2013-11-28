#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDomDocument>
#include <QSettings>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QObject>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init();
    this->signalConnection();
    this->debug();
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
    //this->show();
}
void MainWindow::setDiagMidParent(int height, int width)
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    int startupX = desktopWidget->screenGeometry().width()/2 - width;
    int startupY = desktopWidget->screenGeometry().height()/2 - height;
    this->resize(width, height);
    this->move(startupX, startupY);
    this->show();
}

void MainWindow::init()
{
    //---------------------UI initialize----------------------------
    QDesktopWidget* desktopWidget = QApplication::desktop();
    l = new Login();
    l->setDiagMidParent(270,360);
    ad = new AdminWindow();
    ui->progressBar->setRange(0,5000-1);
    ui->progressBar->setValue(0);
    ui->progressBar->hide();

    //------------------Settings initialize----------------------
    QString setting("/home/daniel/alpaca/Interface_BT/setting.ini");
    //QString setting("/Users/xiaosb/Documents/workspace/alpaca/Interface_BT/setting.ini");
    //QString setting("setting.ini");
    QSettings *configIniRead = new QSettings(setting,QSettings::IniFormat);

    //------------------policyOp initialize---------------------
    this->op = new policyOp(configIniRead->value("/ACCOUNT/USERNAME").toString(),configIniRead->value("/ACCOUNT/PASSWORD").toString(),configIniRead->value("/AGENT_DESC/AGENTCODE").toString());
}

void MainWindow::signalConnection()
{
    connect(this->op,SIGNAL(setProgressBarRange(int)),this,SLOT(slotSetProgressBarRange(int)));
    connect(this->op,SIGNAL(setProgressBarValue(int)),this,SLOT(slotSetProgressBarValue(int)));
    connect(this->l,SIGNAL(authorizedOK()),this,SLOT(show()));
}

void MainWindow::on_pushButton_clicked()
{
    //this->op->GetAlterCommonPolicy("2013-11-28T16:01:20.827","0","0");
    //this->op->GetAllCommonPolicy("0","0");
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
    btDatabase::instance();
    if (allPolicyModel == NULL)
    {
        allPolicyModel = new QSqlTableModel;
        allPolicyModel->setTable("policyDescripition");
    }
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
void MainWindow::exportXls(QString querys)
{
    //QString xlsFilePath = "/home/daniel/Desktop/test.xls";
    QString xlsFilePath = "/Users/xiaosb/Documents/test.xls";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    if (!db.isValid()) {
        QMessageBox::information(NULL, tr("Info："), tr("connect ODBC driver failed!"));
        return;
    }
    QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").arg(xlsFilePath).arg(xlsFilePath);
    db.setDatabaseName(dsn);
    if (!db.open()) {
        QMessageBox::information(NULL, tr("Info:"), tr("Excel open failed！"));
        qDebug()<<db.lastError();
        return;
    }

    QSqlQuery query(db);

    QString strSql = QString("DROP TABLE IF EXISTS `qunarTable`;CREATE TABLE qunarTable(`airlineCode` varchar(20) COLLATE gb2312_bin NOT NULL,`policyCode` varchar(100) NOT NULL,`departureCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,`arrivalCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,`flightRestriction` enum('所有','适用') COLLATE gb2312_bin NOT NULL DEFAULT'所有',`flightNumber` varchar(20) COLLATE gb2312_bin,`timetableRestriction` varchar(45) COLLATE gb2312_bin NOT NULL DEFAULT '',`applicableSpaceCode` varchar(45) COLLATE gb2312_bin NOT NULL,`priceType` varchar(45)  COLLATE gb2312_bin NOT NULL DEFAULT 'Y舱折扣',`price` double NOT NULL,`rebateRate` double NOT NULL,`keepMoney` int(11) NOT NULL DEFAULT 0,`ticketingDateLimitStart` date NOT NULL,`ticketingDateLimitEnd` date NOT NULL,`travellingDateStart` date NOT NULL,`travellingDateEnd` date NOT NULL,`departureTime` varchar(20) NOT NULL DEFAULT '0000-2359',`latestPreticketTimeLimit` date,`earlistPreticketingTimeLimit` date,`remarkInfo` varchar(50) COLLATE gb2312_bin NOT NULL DEFAULT '不可改签、不可改期、不可退票',`spaceInfo` varchar(50) COLLATE gb2312_bin NOT NULL DEFAULT '预付产品',`canPayDirectly` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`isPNRGenerated` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`isPAT:AChecked` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`supplierCode` varchar(45) COLLATE gb2312_bin,`isItinerarySupplied` tinyint(4) NOT NULL DEFAULT 1,`refundRule` int NOT NULL DEFAULT 0,`remarkRule` int NOT NULL DEFAULT 0,`canSign` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '否',`isCreditsupplied` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`certifyID` enum('0','1','2','3','4','5') COLLATE gb2312_bin NOT NULL,`maxAge` tinyint(4) DEFAULT 99,`minAge` tinyint(4) DEFAULT 2,`memo` varchar(200) COLLATE gb2312_bin NOT NULL DEFAULT '') ENGINE=InnoDB DEFAULT CHARSET=gb2312 COLLATE=gb2312_bin;");
    query.exec(strSql);
    query.exec(querys);

    db.close();
    QSqlDatabase::removeDatabase("excelexport");
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
        btDatabase::instance()->execSQL("SELECT * FROM LH_AirTicket.qunarTable into outfile \"/var/tmp/data.csv\";");


    }
}

void MainWindow::on_userManager_clicked()
{
    ad->show();
}
