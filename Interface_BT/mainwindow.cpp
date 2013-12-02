

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


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init();
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
    int startupX = desktopWidget->screenGeometry().width()/2 - width/2;
    int startupY = desktopWidget->screenGeometry().height()/2 - height/2;
    this->setFixedSize(width, height);
    this->move(startupX, startupY);
    this->setWindowTitle(tr("海南浪花商旅有限公司机票网销系统"));

    this->setTabOrder(this->ui->dep, this->ui->arr);
    this->setTabOrder(this->ui->arr, this->ui->companyCode);
    this->setTabOrder(this->ui->companyCode,this->ui->space);
    this->setTabOrder(this->ui->space,this->ui->rateGtCheck);
    this->setTabOrder(this->ui->rateGtCheck, this->ui->rateGt);
    this->setTabOrder(this->ui->rateGt, this->ui->rateLtCheck);
    this->setTabOrder(this->ui->rateLtCheck, this->ui->rateLt);
    this->setTabOrder(this->ui->rateLt, this->ui->LTT);
    this->setTabOrder(this->ui->LTT, this->ui->moneyKeep);
    this->setTabOrder(this->ui->moneyKeep, this->ui->memo);
    this->setTabOrder(this->ui->memo, this->ui->policyNo);
    this->setTabOrder(this->ui->policyNo, this->ui->supplierCode);
    this->setTabOrder(this->ui->supplierCode, this->ui->itineraryCheck);
    this->setTabOrder(this->ui->itineraryCheck, this->ui->payCheck);
    this->setTabOrder(this->ui->payCheck, this->ui->patCheck);
    this->setTabOrder(this->ui->patCheck, this->ui->pnrCheck);
    this->setTabOrder(this->ui->pnrCheck, this->ui->queryButton);
    this->setTabOrder(this->ui->queryButton, this->ui->dumpButton);
    this->setTabOrder(this->ui->dumpButton, this->ui->dumpUpload);
    this->setTabOrder(this->ui->dumpUpload, this->ui->dep);

    this->ui->dep->setFocus();
    this->show();
}

void MainWindow::init()
{

    //------------------Settings initialize----------------------
    QSettings *configIniRead = new QSettings(QString("setting.ini"),QSettings::IniFormat);

    //---------------------UI initialize----------------------------
    d = new dump();
    d->init();
    ad = new AdminWindow();
    if(configIniRead->value("/DEFAULT_ACCOUNT/USERACCOUNT").toString() != "")
        l = new Login(configIniRead->value("/DEFAULT_ACCOUNT/USERACCOUNT").toString());
    else
        l = new Login();
    //------------------policyOp initialize---------------------
    this->op = new policyOp(configIniRead->value("/SQL_ACCOUNT/USERNAME").toString(),configIniRead->value("/SQL_ACCOUNT/PASSWORD").toString(),configIniRead->value("/AGENT_DESC/AGENTCODE").toString());

    this->signalConnection();


    l->setDiagMidParent(270,360);
    allPolicyModel = 0;

    ui->dumpUpload->setEnabled(false);

}

void MainWindow::signalConnection()
{
    connect(this->l,SIGNAL(authorizedOK(QString, QString)),this,SLOT(slotLoggedin(QString, QString)));
    connect(this->ui->action_exit,SIGNAL(triggered()),qApp,SLOT(quit()));
}

void MainWindow::loadSpaceInfo()
{


}


void MainWindow::slotLoggedin(QString username, QString idRes){
    if(idRes == "all")    this->ui->menu_admin->setEnabled(true);
    else this->ui->menu_admin->setEnabled(false);
    this->setDiagMidParent(768,1024);
    this->username = username;
    this->ad->setusername(username);
    this->ui->label_welcome->setText(tr("欢迎回来，")+username);
    this->ui->label_welcome->setAlignment(Qt::AlignCenter);
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

        if(i < space.length()-1)
        {
            if(space.at(i+1).isDigit())
            {
                filter += " or applicableSpaceCode like \"\%" +space[i]+space[i+1]+ "\%\" ";
                i++;
            }
            else
            {
                filter += " or applicableSpaceCode like \"\%" +space[i]+ "\%\" ";
            }
        }
        else
            filter += " or applicableSpaceCode like \"\%" +space[i]+ "\%\" ";
    }
    if (!i)  filter += " or applicableSpaceCode like \"\%\%\")";
    else filter += ")";
    if (space.size() == 0)
        space = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //qDebug()<<filter<<endl;
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
    QVector<QString> space;
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
    QString spaceString = ui->space->text();
    for(int i = 0; i < spaceString.length();i++)
    {
        if(i < spaceString.length() - 1)
        {
            if(spaceString.at(i+1).isDigit())
            {
                space.append(QString(spaceString.at(i))+spaceString.at(i+1));
                i++;
            }
            else
            {
                space.append(spaceString.at(i));
            }
        }
        else
        {
            space.append(spaceString.at(i));
        }
    }
    QVector<QStringList> v = d->dumpFromB2Q(allPolicyModel,ui->moneyKeep->text(),ui->memo->text(),ui->LTT->text(),ui->policyNo->text(),pay,pnr,pat,ui->supplierCode->text(),itinerary,ui->dep->text(),ui->arr->text(),space);

    //filepath.replace(QString("\\"),QString("/"));
    //d->saveAsExcel(filepath,v);
    d->xlsByODBC(filepath,v);
}


void MainWindow::on_action_accountProc_triggered()
{
    ad->setDiagMidParent(480, 640);
}

void MainWindow::on_action_logOut_triggered()
{
    QSettings *settings = new QSettings(QString("setting.ini"),QSettings::IniFormat);
    settings->setValue("/DEFAULT_ACCOUNT/USERACCOUNT",QString(""));
    this->hide();
    this->l->show();
}

void MainWindow::on_action_exit_triggered()
{

}
