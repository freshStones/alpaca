#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QDebug>
#include <QDesktopWidget>
#include <QMessageBox>
#include <btdatabase.h>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    void setDiagMidParent(int height, int width);
    ~Login();

signals:
    void adminAuthorizedOK();
    void commonAuthorizedOK();
private slots:
    void on_loginButton_clicked();

private:
    Ui::Login *ui;
    QString username;
    QString password;
    QString server;
};

#endif // LOGIN_H
