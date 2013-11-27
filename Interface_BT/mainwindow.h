#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "policyOp.h"
#include <QSqlTableModel>
#include "btdatabase.h"
#include "login.h"
#include "adminwindow.h"
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
    void exportXls(QString);
    void configure();
private slots:
    void on_pushButton_clicked();
    void on_queryButton_clicked();

    void on_dumpButton_clicked();

    void on_userManager_clicked();

private:
    Login *l;
    AdminWindow *ad;
    Ui::MainWindow *ui;
    policyOp *op;
    QSqlTableModel *allPolicyModel;

public slots:
    void slotSetProgressBarRange(int);
    void slotSetProgressBarValue(int);
};

#endif // MAINWINDOW_H
