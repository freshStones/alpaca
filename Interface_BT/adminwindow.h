#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QSqlTableModel>
#include <QString>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();
    void setusername(QString);

private slots:
    void on_pushButton_clicked();


    void on_addUser_clicked();

    void on_deleteUser_clicked();

private:
    Ui::AdminWindow *ui;
    QSqlTableModel * allUsers;
    QString username;
};

#endif // ADMINWINDOW_H
