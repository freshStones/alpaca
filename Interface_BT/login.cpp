#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QDebug>
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
    QString usrname = ui->username->text();
    QString pwd = ui->password->text();
    QString md5 = QString().append(QCryptographicHash::hash(pwd.toUtf8(),QCryptographicHash::Md5 ).toHex());
    qDebug()<<md5<<endl;
    if (pwd == "xiaosb")
    {
        this->hide();
        emit authorizedOK();
    }
}
