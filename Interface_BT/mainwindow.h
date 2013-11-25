#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "policyOp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void xmlTest();
    
private:
    Ui::MainWindow *ui;
    policyOp *op;
};

#endif // MAINWINDOW_H
