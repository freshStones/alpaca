/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created: Thu Nov 28 16:36:25 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QTableView *allUsersTable;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *username;
    QLabel *label;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_2;
    QLineEdit *password;

    void setupUi(QWidget *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(639, 462);
        allUsersTable = new QTableView(AdminWindow);
        allUsersTable->setObjectName(QString::fromUtf8("allUsersTable"));
        allUsersTable->setGeometry(QRect(60, 150, 511, 271));
        pushButton = new QPushButton(AdminWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 110, 115, 32));
        pushButton_2 = new QPushButton(AdminWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 110, 115, 32));
        pushButton_3 = new QPushButton(AdminWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(370, 110, 115, 32));
        username = new QLineEdit(AdminWindow);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(210, 30, 113, 21));
        label = new QLabel(AdminWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 30, 62, 19));
        checkBox = new QCheckBox(AdminWindow);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(130, 70, 86, 23));
        checkBox_2 = new QCheckBox(AdminWindow);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(250, 70, 86, 23));
        checkBox_3 = new QCheckBox(AdminWindow);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(370, 70, 86, 23));
        checkBox_4 = new QCheckBox(AdminWindow);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(480, 70, 86, 23));
        label_2 = new QLabel(AdminWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 30, 62, 19));
        password = new QLineEdit(AdminWindow);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(400, 30, 113, 21));

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QWidget *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AdminWindow", "\346\237\245\346\211\276\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AdminWindow", "\346\267\273\345\212\240\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("AdminWindow", "\345\210\240\351\231\244\351\200\211\344\270\255\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdminWindow", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("AdminWindow", "\346\235\203\351\231\2201", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("AdminWindow", "\346\235\203\351\231\2202", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("AdminWindow", "\346\235\203\351\231\2203", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("AdminWindow", "\346\235\203\351\231\2204", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdminWindow", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
