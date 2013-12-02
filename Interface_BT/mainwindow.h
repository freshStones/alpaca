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
    void setDiagMidParent(int height, int width);

private slots:
    void on_pushButton_clicked();
    void on_queryButton_clicked();
    void on_dumpButton_clicked();
    void on_userManager_clicked();

private:
    dump *d;
    Login *l;
    AdminWindow *ad;
    Ui::MainWindow *ui;
    policyOp *op;
    QSqlTableModel *allPolicyModel;

public slots:
    void slotSetProgressBarRange(int);
    void slotSetProgressBarValue(int);
    void slotAdminLoggedin();
};

#endif // MAINWINDOW_H
