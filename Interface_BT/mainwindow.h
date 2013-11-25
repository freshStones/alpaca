#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "policyOp.h"
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

private:
    Ui::MainWindow *ui;
    policyOp *op;

    void xmlTest();

public slots:

    void slotSetProgressBarRange(int);
    void slotSetProgressBarValue(int);
};

#endif // MAINWINDOW_H
