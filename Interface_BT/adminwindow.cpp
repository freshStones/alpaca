#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>
#include <QObject>
#include <QSqlRecord>
#include <QSqlError>
#include <QString>
#include "btdatabase.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    allUsers = NULL;
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_queryButton_clicked()
{
    if (allUsers == NULL)
    {
        allUsers = new QSqlTableModel();
        allUsers->setTable("userList");

    }
    allUsers->select();
    ui->allUsersTable->setModel(allUsers);
}

void AdminWindow::setDiagMidParent(int height, int width)
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    int startupX = desktopWidget->screenGeometry().width()/2 - width/2;
    int startupY = desktopWidget->screenGeometry().height()/2 - height/2;
    this->setFixedSize(width,height);
    this->move(startupX, startupY);
    this->setWindowTitle(tr("海南浪花机票网销系统—账户管理界面"));

    this->setTabOrder(this->ui->username, this->ui->password);
    this->setTabOrder(this->ui->password, this->ui->checkBox_auth1);
    this->setTabOrder(this->ui->checkBox_auth1, this->ui->checkBox_auth2);
    this->setTabOrder(this->ui->checkBox_auth2, this->ui->queryButton);
    this->setTabOrder(this->ui->queryButton, this->ui->addUser);
    this->setTabOrder(this->ui->addUser, this->ui->deleteUser);
    this->setTabOrder(this->ui->deleteUser, this->ui->username);

    this->ui->username->setFocus();
    this->show();
}

void AdminWindow::setusername(QString username)
{
    this->username = username;
}

void AdminWindow::on_addUser_clicked()
{
    if(ui->username->text()==""||ui->password->text()=="")
    {
        QMessageBox::warning(this,QObject::tr("Warning"),QObject::tr("请输入用户名和密码！"),QMessageBox::Ok);
        return;
    }
    this->on_queryButton_clicked();
    QString right("all");
    int rowNum = allUsers->rowCount(); //获得表的行数
    allUsers->insertRow(rowNum); //添加一行,或者用insertRows(0,1),在0行添加1条记录，根据表的排序规则，可能移到与指定行不同的行位置上

    allUsers->setData(allUsers->index(rowNum,1),ui->username->text());
    allUsers->setData(allUsers->index(rowNum,2),ui->password->text());
    allUsers->setData(allUsers->index(rowNum,3),this->username);
    allUsers->setData(allUsers->index(rowNum,4),right);
    allUsers->submit();
}

void AdminWindow::on_deleteUser_clicked()
{
    QItemSelectionModel *selections = ui->allUsersTable->selectionModel();
    QModelIndexList selecteds = selections->selectedIndexes();
    int ok = QMessageBox::warning(this,tr("删除选中的行!"),tr("你确定删除当前选取中的行吗?"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
        foreach (QModelIndex index, selecteds)
        {
            int curRow = index.row(); //删除所有被选中的行
            allUsers->removeRow(curRow);
        }
    }
    allUsers->submit();
    allUsers->select();
    //allUsers->
}
