//Edited by joker,zghember, in late Nov. 2013
//"A Log-in window"
//last modified in 2013/12/02 by joker

#include "login.h"
#include "ui_login.h"

Login::Login(QSettings *setting, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setting = setting;
    this->server = setting->value("/SERVER/HOST").toString();
    this->username = setting->value("/DEFAULT_ACCOUNT/USERACCOUNT").toString();
    this->ifAutoLoginFlag = setting->value("/DEFAULT_ACCOUNT/AUTOLOGIN").toInt();
    loadUserPwd();
    ui->server->setText(server);
    ui->username->setText(this->username);
    if(userMap.contains(this->ui->username->text())){
        this->ui->password->setText(userMap.value(this->ui->username->text()));
        this->ui->checkBox_autoRememberPwd->setChecked(true);
        this->ui->loginButton->setFocus();
    }
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

    if (ifAutoLoginFlag) this->ui->loginButton->click();             //to be solved here
}

void Login::loadUserPwd()
{
    QFile qf("nodalong.src");
    qf.open(QIODevice::ReadOnly);
    QTextStream qts(&qf);
    while(!qts.atEnd()){
        QStringList ss = qts.readLine().split(' ');
        QString pwd(QByteArray().fromBase64(QByteArray().append(ss[1])));
        userMap.insert(ss[0], pwd);
    }
    qf.close();
}

void Login::saveUserPwd()
{
    bool existanceFlag = false;
    QString oldPwd = "";
    QFile qf("nodalong.src");
    qf.open(QIODevice::ReadOnly);
    QTextStream qts(&qf);
    while(!qts.atEnd()){
        QString s = qts.readLine();
        QStringList ss = s.split(' ');
        if(ss[0] == this->username){
            existanceFlag = true;
            oldPwd = ss[1];
            break;
        }
    }
    qf.close();

    qf.open(QIODevice::ReadOnly);
    qts.reset();
    QString tempStr = qts.readAll();

    qf.close();
    if(existanceFlag == true)   tempStr = tempStr.replace(this->username+" "+oldPwd, this->username+" "+QByteArray().append(this->password).toBase64());
    else tempStr += (this->username + " " + QByteArray().append(this->password).toBase64() + "\r\n");

    qf.open(QIODevice::WriteOnly);
    qts.reset();
    qts << tempStr;
    qf.close();
}

void Login::on_loginButton_clicked()
{
    this ->server = ui->server->text();
    this ->username = ui->username->text();
    this->password = ui->password->text();
    btDatabase::setconfig(username,password,server);

    if(!btDatabase::instance()->isOpen()){
        QMessageBox::warning(this,QObject::tr("Warning"),QObject::tr("数据库无法连接"),QMessageBox::Ok);
        ui->server->setFocus();
        ui->server->selectAll();
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

        setting->setValue("/SERVER/HOST", this->ui->server->text());
        setting->setValue("/DEFAULT_ACCOUNT/USERACCOUNT", this->ui->username->text());
        if(this->ui->checkBox_autoRememberPwd->isChecked() == true) saveUserPwd();
        if(this->ui->checkBox_autoLogin->isChecked() == true){
            setting->setValue("/DEFAULT_ACCOUNT/AUTOLOGIN",1);
        }
        this->hide();
        emit authorizedOK(this->username, idRes);

//        if(idRes == "all")  emit authorizedOK(this->username, idRes);
//        else emit commonAuthorizedOK();
    }
}

void Login::on_checkBox_autoLogin_stateChanged(int arg1)
{
    this->ui->checkBox_autoRememberPwd->setChecked(arg1);
}

void Login::on_checkBox_autoRememberPwd_clicked()
{
    if(this->ui->checkBox_autoLogin->isChecked()&& !this->ui->checkBox_autoRememberPwd->isChecked())
        this->ui->checkBox_autoRememberPwd->setChecked(true);
}

void Login::on_username_editingFinished()
{
    if(userMap.contains(this->ui->username->text())){
        this->ui->password->setText(userMap.value(this->ui->username->text()));
        this->ui->checkBox_autoRememberPwd->setChecked(true);
        this->ui->loginButton->setFocus();
    }
}

void Login::on_username_textEdited(const QString &arg1)
{
    this->ui->password->clear();
    this->ui->checkBox_autoRememberPwd->setChecked(false);
}
