#include "login.h"
#include "ui_login.h"
#include "btdatabase.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::setDiagMidParent(int height, int width)
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    int startupX = desktopWidget->screenGeometry().width()/2 - width/2;
    int startupY = desktopWidget->screenGeometry().height()/2 - height/2;
    this->setFixedSize(width,height);
    this->move(startupX, startupY);
    this->setWindowTitle(tr("海南浪花机票网销系统—登陆界面"));
    this->ui->username->selectAll();
    this->ui->username->setFocus();
    this->setTabOrder(this->ui->username,this->ui->password);
    this->setTabOrder(this->ui->password,this->ui->checkBox_autoLogin);
    this->setTabOrder(this->ui->checkBox_autoLogin,this->ui->checkBox_autoRememberPwd);
    this->setTabOrder(this->ui->checkBox_autoRememberPwd,this->ui->loginButton);
    this->setTabOrder(this->ui->loginButton,this->ui->server);
    this->ui->loginButton->setAutoDefault(true);

    this->show();
}

void Login::on_loginButton_clicked()
{
    this ->server = ui->server->text();
    this ->username = ui->username->text();
    //this-> password = QString().append(QCryptographicHash::hash(ui->password->text().toUtf8(),QCryptographicHash::Md5 ).toHex());
    this->password = ui->password->text();
    btDatabase::setconfig(username,ui->password->text(),server);
    //btDatabase::instance()->querySQL(QString("select * from users where user = \"%1\"").arg(username);
    //if (this->password == "3f5b31f8506cfb9a606553978da02d9f")
    if(!btDatabase::instance()->isOpen()){
        QMessageBox::warning(this,QObject::tr("Warning"),QObject::tr("数据库无法连接"),QMessageBox::Ok);
        ui->server->setText("");
        return;
    }

    QString idRes = btDatabase::instance()->identify(this->username, this->password);
    if(idRes == "unauthorized id")
    {
        QMessageBox::warning(this,QObject::tr("Warning"),QObject::tr("帐号密码错误！"),QMessageBox::Ok);
        ui->password->clear();
        ui->username->setFocus();
        ui->username->selectAll();

    }
    else{
        this->hide();
        if(idRes == "all")emit adminAuthorizedOK();
        else emit commonAuthorizedOK();
    }
}
