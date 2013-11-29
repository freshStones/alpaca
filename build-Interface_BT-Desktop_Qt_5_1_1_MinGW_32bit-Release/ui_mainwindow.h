/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTabWidget *tabs;
    QWidget *policy;
    QTableView *allPolicyTableView;
    QLineEdit *dep;
    QLineEdit *arr;
    QLineEdit *supplierCode;
    QLineEdit *LTT;
    QLineEdit *policyNo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *memo;
    QCheckBox *patCheck;
    QCheckBox *pnrCheck;
    QCheckBox *itineraryCheck;
    QCheckBox *payCheck;
    QLineEdit *rateGt;
    QCheckBox *rateGtCheck;
    QCheckBox *rateLtCheck;
    QLineEdit *rateLt;
    QLabel *label_8;
    QLineEdit *moneyKeep;
    QPushButton *queryButton;
    QPushButton *dumpButton;
    QPushButton *dumpUpload;
    QLabel *label_9;
    QLineEdit *companyCode;
    QLabel *label_10;
    QLineEdit *space;
    QWidget *tab_2;
    QTableView *tableView_2;
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *userManager;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(904, 728);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 640, 115, 32));
        tabs = new QTabWidget(centralwidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setGeometry(QRect(10, 30, 881, 541));
        policy = new QWidget();
        policy->setObjectName(QStringLiteral("policy"));
        allPolicyTableView = new QTableView(policy);
        allPolicyTableView->setObjectName(QStringLiteral("allPolicyTableView"));
        allPolicyTableView->setGeometry(QRect(20, 200, 851, 311));
        dep = new QLineEdit(policy);
        dep->setObjectName(QStringLiteral("dep"));
        dep->setGeometry(QRect(200, 10, 71, 21));
        arr = new QLineEdit(policy);
        arr->setObjectName(QStringLiteral("arr"));
        arr->setGeometry(QRect(200, 40, 71, 21));
        supplierCode = new QLineEdit(policy);
        supplierCode->setObjectName(QStringLiteral("supplierCode"));
        supplierCode->setGeometry(QRect(540, 130, 111, 21));
        LTT = new QLineEdit(policy);
        LTT->setObjectName(QStringLiteral("LTT"));
        LTT->setGeometry(QRect(540, 10, 111, 21));
        policyNo = new QLineEdit(policy);
        policyNo->setObjectName(QStringLiteral("policyNo"));
        policyNo->setGeometry(QRect(540, 100, 111, 21));
        label_2 = new QLabel(policy);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 10, 91, 19));
        label_3 = new QLabel(policy);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 40, 81, 19));
        label_4 = new QLabel(policy);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(450, 100, 62, 19));
        label_5 = new QLabel(policy);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(450, 130, 62, 19));
        label_6 = new QLabel(policy);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(450, 10, 91, 19));
        label_7 = new QLabel(policy);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(450, 70, 62, 19));
        memo = new QLineEdit(policy);
        memo->setObjectName(QStringLiteral("memo"));
        memo->setGeometry(QRect(540, 70, 113, 21));
        patCheck = new QCheckBox(policy);
        patCheck->setObjectName(QStringLiteral("patCheck"));
        patCheck->setGeometry(QRect(680, 70, 86, 23));
        patCheck->setChecked(true);
        pnrCheck = new QCheckBox(policy);
        pnrCheck->setObjectName(QStringLiteral("pnrCheck"));
        pnrCheck->setGeometry(QRect(680, 100, 86, 23));
        pnrCheck->setChecked(true);
        itineraryCheck = new QCheckBox(policy);
        itineraryCheck->setObjectName(QStringLiteral("itineraryCheck"));
        itineraryCheck->setGeometry(QRect(680, 10, 86, 23));
        itineraryCheck->setAcceptDrops(true);
        itineraryCheck->setChecked(true);
        payCheck = new QCheckBox(policy);
        payCheck->setObjectName(QStringLiteral("payCheck"));
        payCheck->setGeometry(QRect(680, 40, 86, 23));
        payCheck->setChecked(true);
        rateGt = new QLineEdit(policy);
        rateGt->setObjectName(QStringLiteral("rateGt"));
        rateGt->setGeometry(QRect(170, 130, 31, 21));
        rateGtCheck = new QCheckBox(policy);
        rateGtCheck->setObjectName(QStringLiteral("rateGtCheck"));
        rateGtCheck->setGeometry(QRect(110, 130, 61, 23));
        rateLtCheck = new QCheckBox(policy);
        rateLtCheck->setObjectName(QStringLiteral("rateLtCheck"));
        rateLtCheck->setGeometry(QRect(210, 130, 61, 23));
        rateLt = new QLineEdit(policy);
        rateLt->setObjectName(QStringLiteral("rateLt"));
        rateLt->setGeometry(QRect(270, 130, 31, 21));
        label_8 = new QLabel(policy);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(450, 40, 41, 19));
        moneyKeep = new QLineEdit(policy);
        moneyKeep->setObjectName(QStringLiteral("moneyKeep"));
        moneyKeep->setGeometry(QRect(540, 40, 111, 21));
        queryButton = new QPushButton(policy);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(120, 160, 141, 32));
        dumpButton = new QPushButton(policy);
        dumpButton->setObjectName(QStringLiteral("dumpButton"));
        dumpButton->setGeometry(QRect(470, 160, 141, 32));
        dumpUpload = new QPushButton(policy);
        dumpUpload->setObjectName(QStringLiteral("dumpUpload"));
        dumpUpload->setGeometry(QRect(620, 160, 141, 32));
        label_9 = new QLabel(policy);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(110, 70, 81, 20));
        companyCode = new QLineEdit(policy);
        companyCode->setObjectName(QStringLiteral("companyCode"));
        companyCode->setGeometry(QRect(200, 70, 71, 21));
        label_10 = new QLabel(policy);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(110, 100, 62, 19));
        space = new QLineEdit(policy);
        space->setObjectName(QStringLiteral("space"));
        space->setGeometry(QRect(200, 100, 71, 21));
        tabs->addTab(policy, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(0, 60, 691, 301));
        tabs->addTab(tab_2, QString());
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 590, 801, 23));
        progressBar->setValue(24);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 620, 801, 17));
        label->setAlignment(Qt::AlignCenter);
        userManager = new QPushButton(centralwidget);
        userManager->setObjectName(QStringLiteral("userManager"));
        userManager->setGeometry(QRect(760, 640, 115, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 904, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\247\213\345\217\221(\344\270\211\345\255\227\347\240\201):", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\210\260\350\276\276(\344\270\211\345\255\227\347\240\201):", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\224\277\347\255\226\344\273\243\347\240\201:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Office\345\217\267:", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\234\200\346\231\232\346\217\220\345\211\215\345\207\272\347\245\250:", 0));
        label_7->setText(QApplication::translate("MainWindow", "\347\245\250\345\212\241\350\257\264\346\230\216:", 0));
        patCheck->setText(QApplication::translate("MainWindow", "PAT", 0));
        pnrCheck->setText(QApplication::translate("MainWindow", "pnr", 0));
        itineraryCheck->setText(QApplication::translate("MainWindow", "\350\241\214\347\250\213\345\215\225", 0));
        payCheck->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230", 0));
        rateGtCheck->setText(QApplication::translate("MainWindow", "\350\277\224\347\202\271>", 0));
        rateLtCheck->setText(QApplication::translate("MainWindow", "\350\277\224\347\202\271<", 0));
        label_8->setText(QApplication::translate("MainWindow", "\347\225\231\351\222\261:", 0));
        queryButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0));
        dumpButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\344\277\235\345\255\230", 0));
        dumpUpload->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\344\277\235\345\255\230\345\271\266\350\207\252\345\212\250\344\270\212\344\274\240", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\210\252\345\217\270(\344\270\244\345\255\227\347\240\201):", 0));
        companyCode->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\350\210\261\344\275\215:", 0));
        tabs->setTabText(tabs->indexOf(policy), QApplication::translate("MainWindow", "\347\255\233\346\224\277\347\255\226", 0));
        tabs->setTabText(tabs->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
        label->setText(QString());
        userManager->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
