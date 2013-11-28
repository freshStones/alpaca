/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Thu Nov 28 23:54:05 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *loginButton;
    QLineEdit *username;
    QLabel *label_username;
    QLabel *label_passport;
    QLineEdit *password;
    QLineEdit *server;
    QLabel *label_server;
    QCheckBox *checkBox_autoLogin;
    QCheckBox *checkBox_autoRememberPwd;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(360, 270);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(110, 210, 115, 32));
        loginButton->setFocusPolicy(Qt::StrongFocus);
        loginButton->setAcceptDrops(false);
        loginButton->setCheckable(false);
        username = new QLineEdit(Login);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(151, 90, 131, 21));
        label_username = new QLabel(Login);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(59, 90, 62, 19));
        label_passport = new QLabel(Login);
        label_passport->setObjectName(QString::fromUtf8("label_passport"));
        label_passport->setGeometry(QRect(59, 130, 62, 19));
        password = new QLineEdit(Login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(149, 130, 131, 21));
        password->setContextMenuPolicy(Qt::PreventContextMenu);
        password->setEchoMode(QLineEdit::Password);
        server = new QLineEdit(Login);
        server->setObjectName(QString::fromUtf8("server"));
        server->setGeometry(QRect(149, 50, 131, 21));
        label_server = new QLabel(Login);
        label_server->setObjectName(QString::fromUtf8("label_server"));
        label_server->setGeometry(QRect(60, 50, 81, 21));
        checkBox_autoLogin = new QCheckBox(Login);
        checkBox_autoLogin->setObjectName(QString::fromUtf8("checkBox_autoLogin"));
        checkBox_autoLogin->setGeometry(QRect(70, 170, 97, 22));
        checkBox_autoRememberPwd = new QCheckBox(Login);
        checkBox_autoRememberPwd->setObjectName(QString::fromUtf8("checkBox_autoRememberPwd"));
        checkBox_autoRememberPwd->setGeometry(QRect(190, 170, 97, 22));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("Login", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("Login", "root", 0, QApplication::UnicodeUTF8));
        label_username->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_passport->setText(QApplication::translate("Login", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        password->setInputMask(QString());
        password->setText(QApplication::translate("Login", "raccoon", 0, QApplication::UnicodeUTF8));
        server->setText(QApplication::translate("Login", "162.105.81.242", 0, QApplication::UnicodeUTF8));
        label_server->setText(QApplication::translate("Login", "\346\234\215\345\212\241\345\231\250:", 0, QApplication::UnicodeUTF8));
        checkBox_autoLogin->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        checkBox_autoRememberPwd->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
