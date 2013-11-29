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
#include <QVector>
#include <QStringList>

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

    //------------------Settings initialize----------------------
    QString setting("/home/daniel/alpaca/Interface_BT/setting.ini");
    //QString setting("/Users/xiaosb/Documents/workspace/alpaca/Interface_BT/setting.ini");
    //QString setting("setting.ini");
    QSettings *configIniRead = new QSettings(setting,QSettings::IniFormat);

    //---------------------UI initialize----------------------------
    QDesktopWidget* desktopWidget = QApplication::desktop();
    l = new Login();
    allPolicyModel = 0;
    d = new dump();
    d->init();

    l->setDiagMidParent(270,360);
    ad = new AdminWindow();
    ui->progressBar->setRange(0,5000-1);
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
    ui->userManager->hide();

    //------------------policyOp initialize---------------------
    this->op = new policyOp(configIniRead->value("/ACCOUNT/USERNAME").toString(),configIniRead->value("/ACCOUNT/PASSWORD").toString(),configIniRead->value("/AGENT_DESC/AGENTCODE").toString());
}

void MainWindow::signalConnection()
{
    connect(this->op,SIGNAL(setProgressBarRange(int)),this,SLOT(slotSetProgressBarRange(int)));
    connect(this->op,SIGNAL(setProgressBarValue(int)),this,SLOT(slotSetProgressBarValue(int)));
    connect(this->l,SIGNAL(adminAuthorizedOK()),this,SLOT(slotAdminLoggedin()));
    connect(this->l,SIGNAL(commonAuthorizedOK()),this,SLOT(show()));
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

void MainWindow::slotAdminLoggedin(){
    this->ui->userManager->show();
    this->show();
}

void MainWindow::on_queryButton_clicked()
{
    btDatabase::instance();
    if (allPolicyModel == NULL)
    {
        allPolicyModel = new QSqlTableModel;
        allPolicyModel->setTable("policyDescripition");
    }
    QString filter("departureCityCodes like \"\%" + ui->dep->text() + "\%\""+" and arrivalCityCodes like \"\%" + ui->arr->text() + "\%\"" );
    filter += " and airlinecode like \"\%" + ui->companyCode->text() + "\" and policyStatus = 1 and (false ";
    QString space = ui->space->text();
    int i = 0;
    for (i = 0; i < space.length();i++)
    {
        filter += " or applicableSpaceCode like \"\%" +space[i]+ "\%\" ";
    }
    if (!i)  filter += " or applicableSpaceCode like \"\%\%\")";
    else filter += ")";
    qDebug()<<filter<<endl;
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
    QString pay,pnr,pat,itinerary;
    if (ui->payCheck->checkState() ==Qt::Checked)
        pay = "是";
    else pay = "否";
    if(ui->pnrCheck->checkState() == Qt::Checked)
        pnr = "是";
    else pnr = "否";
    if (ui->patCheck->checkState() == Qt::Checked)
        pat = "是";
    else pat = "否";
    if (ui->itineraryCheck->checkState() == Qt::Checked)
        itinerary = "0";
    else itinerary = "1";
    QString filepath=QFileDialog::getSaveFileName(this,QObject::tr("Save orbit"),".",QObject::tr("Microsoft Office 2000 (*.xls)"));//获取保存路径
    QVector<QStringList> v = d->dumpFromB2Q(allPolicyModel,ui->moneyKeep->text(),ui->memo->text(),ui->LTT->text(),ui->policyNo->text(),pay,pnr,pat,ui->supplierCode->text(),itinerary,ui->dep->text(),ui->arr->text(),ui->space->text());

    //filepath.replace(QString("\\"),QString("/"));
    //d->saveAsExcel(filepath,v);
    d->xlsByODBC(filepath,v);
}

void MainWindow::on_userManager_clicked()
{
    ad->show();
}
