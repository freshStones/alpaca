/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Thu Nov 28 16:36:25 2013
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *pushButton;
    QLineEdit *username;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *password;
    QLineEdit *server;
    QLabel *label_3;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 210, 115, 32));
        username = new QLineEdit(Login);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(190, 100, 113, 21));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 100, 62, 19));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 160, 62, 19));
        password = new QLineEdit(Login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(190, 160, 113, 21));
        password->setContextMenuPolicy(Qt::PreventContextMenu);
        password->setEchoMode(QLineEdit::Password);
        server = new QLineEdit(Login);
        server->setObjectName(QString::fromUtf8("server"));
        server->setGeometry(QRect(190, 50, 113, 21));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 50, 62, 19));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Login", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("Login", "root", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        password->setInputMask(QString());
        password->setText(QApplication::translate("Login", "raccoon", 0, QApplication::UnicodeUTF8));
        server->setText(QApplication::translate("Login", "162.105.81.242", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Login", "\346\234\215\345\212\241\345\231\250:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
