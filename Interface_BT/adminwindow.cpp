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

void AdminWindow::on_pushButton_clicked()
{
    if (allUsers == NULL)
    {
        allUsers = new QSqlTableModel();
        allUsers->setTable("userList");

    }
    allUsers->select();
    ui->allUsersTable->setModel(allUsers);
}


void AdminWindow::on_addUser_clicked()
{
    QString right("all");
    QString grantBy("xiaosb");
    int rowNum = allUsers->rowCount(); //获得表的行数
    allUsers->insertRow(rowNum); //添加一行,或者用insertRows(0,1),在0行添加1条记录，根据表的排序规则，可能移到与指定行不同的行位置上
    allUsers->setData(allUsers->index(rowNum,1),ui->username->text()); //因为这里设置了ID为主键，所以必须给新行添加id属性值,id字段在第0列上
    allUsers->setData(allUsers->index(rowNum,2),ui->password->text());
    allUsers->setData(allUsers->index(rowNum,3),grantBy);
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
    //allUsers->
}
