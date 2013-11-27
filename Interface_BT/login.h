#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QDebug>
#include <btdatabase.h>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
signals:
    void authorizedOK();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QString username;
    QString password;
    QString server;
};

#endif // LOGIN_H
