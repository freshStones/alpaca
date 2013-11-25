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
    
private:
    Ui::MainWindow *ui;
    policyOp *op;
    QSqlTableModel *allPolicyModel;

public slots:

};

#endif // MAINWINDOW_H
