#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "policyOp.h"
#include <QSqlTableModel>
//#include "btdatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
    void on_queryButton_clicked();

private:
    Ui::MainWindow *ui;
    policyOp *op;
    QSqlTableModel *allPolicyModel;

public slots:

    void slotSetProgressBarRange(int);
    void slotSetProgressBarValue(int);
};

#endif // MAINWINDOW_H
