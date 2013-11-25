#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDomDocument>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    btDatabase::instance();
    allPolicyModel = new QSqlTableModel;
    allPolicyModel->setTable("policyDescripition");
    allPolicyModel->select();
    ui->allPolicyTableView->setModel(allPolicyModel);

    //QSettings *configIniRead = new QSettings("/home/daniel/alpaca/Interface_BT/setting.ini",QSettings::IniFormat);
    //this->op = new policyOp(configIniRead->value("/ACCOUNT/USERNAME").toString(),configIniRead->value("/ACCOUNT/PASSWORD").toString(),configIniRead->value("/AGENT_DESC/AGENTCODE").toString());
    //this->op->GetAlterCommonPolicy("2013-11-25T23:30:20.827","0","0");
}

MainWindow::~MainWindow()
{
    delete ui;
}
