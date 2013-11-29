/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

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
    QCheckBox *checkBox_4;
    QLabel *label_2;
    QLineEdit *password;

    void setupUi(QWidget *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(640, 480);
        allUsersTable = new QTableView(AdminWindow);
        allUsersTable->setObjectName(QStringLiteral("allUsersTable"));
        allUsersTable->setGeometry(QRect(60, 150, 511, 271));
        pushButton = new QPushButton(AdminWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 110, 115, 32));
        pushButton_2 = new QPushButton(AdminWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 110, 115, 32));
        pushButton_3 = new QPushButton(AdminWindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(370, 110, 115, 32));
        username = new QLineEdit(AdminWindow);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(180, 30, 113, 21));
        label = new QLabel(AdminWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 30, 62, 19));
        checkBox = new QCheckBox(AdminWindow);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(190, 70, 86, 23));
        checkBox_4 = new QCheckBox(AdminWindow);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(330, 70, 86, 23));
        label_2 = new QLabel(AdminWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 30, 62, 19));
        password = new QLineEdit(AdminWindow);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(380, 30, 113, 21));

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QWidget *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Form", 0));
        pushButton->setText(QApplication::translate("AdminWindow", "\346\237\245\346\211\276\347\224\250\346\210\267", 0));
        pushButton_2->setText(QApplication::translate("AdminWindow", "\346\267\273\345\212\240\347\224\250\346\210\267", 0));
        pushButton_3->setText(QApplication::translate("AdminWindow", "\345\210\240\351\231\244\351\200\211\344\270\255\347\224\250\346\210\267", 0));
        label->setText(QApplication::translate("AdminWindow", "\347\224\250\346\210\267\345\220\215:", 0));
        checkBox->setText(QApplication::translate("AdminWindow", "\346\235\203\351\231\2201", 0));
        checkBox_4->setText(QApplication::translate("AdminWindow", "\346\235\203\351\231\2204", 0));
        label_2->setText(QApplication::translate("AdminWindow", "\345\257\206\347\240\201:", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
