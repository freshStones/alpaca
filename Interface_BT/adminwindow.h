#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QSqlTableModel>
#include <QString>
#include <QDesktopWidget>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    void setDiagMidParent(int height, int width);
    void setusername(QString);
    ~AdminWindow();

private slots:
    void on_queryButton_clicked();

    void on_addUser_clicked();

    void on_deleteUser_clicked();

private:
    Ui::AdminWindow *ui;
    QSqlTableModel * allUsers;
    QString username;
};

#endif // ADMINWINDOW_H
