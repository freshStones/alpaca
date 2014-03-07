#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtCore/qglobal.h>
#include <QTextCodec>
#include <QObject>
#include <QSharedMemory>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QPair>
#include <QVector>

#include "policyOp.h"
#include "btdatabase.h"
#include "login.h"
#include "adminwindow.h"
#include "dump.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void signalConnection();
    void debug();
    void init();
    void loadSpaceInfo();
    void setDiagMidParent(int height, int width);

private slots:
    void on_queryButton_clicked();
    void on_dumpButton_clicked();
    void on_action_accountProc_triggered();
    void on_action_logOut_triggered();

    void on_action_exit_triggered();

private:
    dump *dumpExcelOp;
    QString username;
    Login *loginWindow;
    AdminWindow *adminWindow;
    Ui::MainWindow *ui;
    policyOp *op;
    QSqlTableModel *allPolicyModel;
    QVector<QPair<QString,QString> > qv[11];  //account from 0.9,0.85 to 0.4

public slots:
    void slotLoggedin(QString, QString);
};

#endif // MAINWINDOW_H
