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
