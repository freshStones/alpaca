#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QDebug>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QMap>
#include <QSettings>

#include <btdatabase.h>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    explicit Login(const QString username);
    void setDiagMidParent(int height, int width);
    ~Login();

private:
    void loadUserPwd();
    void saveUserPwd();

signals:
    void adminAuthorizedOK();
    void commonAuthorizedOK();
private slots:
    void on_loginButton_clicked();

    void on_checkBox_autoLogin_stateChanged(int arg1);

    void on_checkBox_autoRememberPwd_clicked();

    void on_username_editingFinished();

    void on_username_textEdited(const QString &arg1);

private:
    Ui::Login *ui;
    QString username;
    QString password;
    QString server;
    QMap<QString, QString> userMap;

    bool ifAutoLoginFlag;
};

#endif // LOGIN_H
