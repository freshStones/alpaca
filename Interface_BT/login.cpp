#include "login.h"
#include "ui_login.h"
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
    this->setWindowTitle(tr("登陆界面"));
    //this->ui->username->setFocus();
    this->setTabOrder(this->ui->username,this->ui->pushButton);
    this->setTabOrder(this->ui->password,this->ui->pushButton);
    this->ui->pushButton->setFocus();

    this->show();
}


void Login::on_pushButton_clicked()
{
    this ->server = ui->server->text();
    this ->username = ui->username->text();
    this-> password = QString().append(QCryptographicHash::hash(ui->password->text().toUtf8(),QCryptographicHash::Md5 ).toHex());
    btDatabase::setconfig(username,ui->password->text(),server);
    //btDatabase::instance()->querySQL(QString("select * from users where user = \"%1\"").arg(username);
    if (this->password == "3f5b31f8506cfb9a606553978da02d9f")
    {
        this->hide();
        emit authorizedOK();
    }
}
