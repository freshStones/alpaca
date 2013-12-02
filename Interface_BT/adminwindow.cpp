#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>
#include <QObject>
#include <QSqlRecord>
#include <QSqlError>

AdminWindow::AdminWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_clicked()
{
    if (allUsers == NULL)
    {
        allUsers = new QSqlTableModel();
        allUsers->setTable("users");
    }
    allUsers->select();
    ui->allUsersTable->setModel(allUsers);
}

void AdminWindow::on_pushButton_2_clicked()
{
   // QString query = QString("insert into users(username,password,right) values(%1,%2,%3)").arg(ui->username).arg(ui->password).arg();

}
