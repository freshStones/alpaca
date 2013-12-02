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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_alterPwd;
    QAction *action_logOut;
    QAction *action_exit;
    QAction *action_accountProc;
    QWidget *centralwidget;
    QTabWidget *tabs;
    QWidget *policy;
    QTableView *allPolicyTableView;
    QLineEdit *dep;
    QLineEdit *arr;
    QLineEdit *supplierCode;
    QLineEdit *LTT;
    QLineEdit *policyNo;
    QLabel *label_dep;
    QLabel *label_arr;
    QLabel *label_policyNo;
    QLabel *label_supplierCode;
    QLabel *label_LTT;
    QLabel *label_memo;
    QLineEdit *memo;
    QCheckBox *patCheck;
    QCheckBox *pnrCheck;
    QCheckBox *itineraryCheck;
    QCheckBox *payCheck;
    QLineEdit *rateGt;
    QCheckBox *rateGtCheck;
    QCheckBox *rateLtCheck;
    QLineEdit *rateLt;
    QLabel *label_moneyKeep;
    QLineEdit *moneyKeep;
    QPushButton *queryButton;
    QPushButton *dumpButton;
    QPushButton *dumpUpload;
    QLabel *label_companyCode;
    QLineEdit *companyCode;
    QLabel *label_space;
    QLineEdit *space;
    QWidget *tab_unknown;
    QLabel *label_welcome;
    QMenuBar *menubar;
    QMenu *menu_common;
    QMenu *menu_admin;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        action_alterPwd = new QAction(MainWindow);
        action_alterPwd->setObjectName(QStringLiteral("action_alterPwd"));
        action_logOut = new QAction(MainWindow);
        action_logOut->setObjectName(QStringLiteral("action_logOut"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_accountProc = new QAction(MainWindow);
        action_accountProc->setObjectName(QStringLiteral("action_accountProc"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabs = new QTabWidget(centralwidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setGeometry(QRect(10, 30, 1011, 701));
        policy = new QWidget();
        policy->setObjectName(QStringLiteral("policy"));
        allPolicyTableView = new QTableView(policy);
        allPolicyTableView->setObjectName(QStringLiteral("allPolicyTableView"));
        allPolicyTableView->setGeometry(QRect(20, 200, 971, 461));
        dep = new QLineEdit(policy);
        dep->setObjectName(QStringLiteral("dep"));
        dep->setGeometry(QRect(280, 10, 111, 21));
        arr = new QLineEdit(policy);
        arr->setObjectName(QStringLiteral("arr"));
        arr->setGeometry(QRect(280, 40, 111, 21));
        supplierCode = new QLineEdit(policy);
        supplierCode->setObjectName(QStringLiteral("supplierCode"));
        supplierCode->setGeometry(QRect(570, 130, 111, 21));
        LTT = new QLineEdit(policy);
        LTT->setObjectName(QStringLiteral("LTT"));
        LTT->setGeometry(QRect(570, 10, 111, 21));
        policyNo = new QLineEdit(policy);
        policyNo->setObjectName(QStringLiteral("policyNo"));
        policyNo->setGeometry(QRect(570, 100, 111, 21));
        label_dep = new QLabel(policy);
        label_dep->setObjectName(QStringLiteral("label_dep"));
        label_dep->setGeometry(QRect(160, 10, 91, 19));
        label_arr = new QLabel(policy);
        label_arr->setObjectName(QStringLiteral("label_arr"));
        label_arr->setGeometry(QRect(160, 40, 81, 19));
        label_policyNo = new QLabel(policy);
        label_policyNo->setObjectName(QStringLiteral("label_policyNo"));
        label_policyNo->setGeometry(QRect(480, 100, 62, 19));
        label_supplierCode = new QLabel(policy);
        label_supplierCode->setObjectName(QStringLiteral("label_supplierCode"));
        label_supplierCode->setGeometry(QRect(480, 130, 62, 19));
        label_LTT = new QLabel(policy);
        label_LTT->setObjectName(QStringLiteral("label_LTT"));
        label_LTT->setGeometry(QRect(480, 10, 91, 19));
        label_memo = new QLabel(policy);
        label_memo->setObjectName(QStringLiteral("label_memo"));
        label_memo->setGeometry(QRect(480, 70, 62, 19));
        memo = new QLineEdit(policy);
        memo->setObjectName(QStringLiteral("memo"));
        memo->setGeometry(QRect(570, 70, 113, 21));
        patCheck = new QCheckBox(policy);
        patCheck->setObjectName(QStringLiteral("patCheck"));
        patCheck->setGeometry(QRect(780, 70, 86, 23));
        patCheck->setChecked(true);
        pnrCheck = new QCheckBox(policy);
        pnrCheck->setObjectName(QStringLiteral("pnrCheck"));
        pnrCheck->setGeometry(QRect(780, 100, 86, 23));
        pnrCheck->setChecked(true);
        itineraryCheck = new QCheckBox(policy);
        itineraryCheck->setObjectName(QStringLiteral("itineraryCheck"));
        itineraryCheck->setGeometry(QRect(780, 10, 86, 23));
        itineraryCheck->setAcceptDrops(true);
        itineraryCheck->setChecked(true);
        payCheck = new QCheckBox(policy);
        payCheck->setObjectName(QStringLiteral("payCheck"));
        payCheck->setGeometry(QRect(780, 40, 86, 23));
        payCheck->setChecked(true);
        rateGt = new QLineEdit(policy);
        rateGt->setObjectName(QStringLiteral("rateGt"));
        rateGt->setGeometry(QRect(220, 130, 31, 21));
        rateGtCheck = new QCheckBox(policy);
        rateGtCheck->setObjectName(QStringLiteral("rateGtCheck"));
        rateGtCheck->setGeometry(QRect(160, 130, 61, 23));
        rateLtCheck = new QCheckBox(policy);
        rateLtCheck->setObjectName(QStringLiteral("rateLtCheck"));
        rateLtCheck->setGeometry(QRect(270, 130, 61, 23));
        rateLt = new QLineEdit(policy);
        rateLt->setObjectName(QStringLiteral("rateLt"));
        rateLt->setGeometry(QRect(330, 130, 31, 21));
        label_moneyKeep = new QLabel(policy);
        label_moneyKeep->setObjectName(QStringLiteral("label_moneyKeep"));
        label_moneyKeep->setGeometry(QRect(480, 40, 41, 19));
        moneyKeep = new QLineEdit(policy);
        moneyKeep->setObjectName(QStringLiteral("moneyKeep"));
        moneyKeep->setGeometry(QRect(570, 40, 111, 21));
        queryButton = new QPushButton(policy);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(200, 160, 141, 32));
        dumpButton = new QPushButton(policy);
        dumpButton->setObjectName(QStringLiteral("dumpButton"));
        dumpButton->setGeometry(QRect(480, 160, 141, 32));
        dumpUpload = new QPushButton(policy);
        dumpUpload->setObjectName(QStringLiteral("dumpUpload"));
        dumpUpload->setGeometry(QRect(690, 160, 141, 32));
        label_companyCode = new QLabel(policy);
        label_companyCode->setObjectName(QStringLiteral("label_companyCode"));
        label_companyCode->setGeometry(QRect(160, 70, 81, 20));
        companyCode = new QLineEdit(policy);
        companyCode->setObjectName(QStringLiteral("companyCode"));
        companyCode->setGeometry(QRect(280, 70, 111, 21));
        label_space = new QLabel(policy);
        label_space->setObjectName(QStringLiteral("label_space"));
        label_space->setGeometry(QRect(160, 100, 62, 19));
        space = new QLineEdit(policy);
        space->setObjectName(QStringLiteral("space"));
        space->setGeometry(QRect(280, 100, 111, 21));
        tabs->addTab(policy, QString());
        tab_unknown = new QWidget();
        tab_unknown->setObjectName(QStringLiteral("tab_unknown"));
        tabs->addTab(tab_unknown, QString());
        label_welcome = new QLabel(centralwidget);
        label_welcome->setObjectName(QStringLiteral("label_welcome"));
        label_welcome->setGeometry(QRect(860, 10, 161, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        label_welcome->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 21));
        menu_common = new QMenu(menubar);
        menu_common->setObjectName(QStringLiteral("menu_common"));
        menu_admin = new QMenu(menubar);
        menu_admin->setObjectName(QStringLiteral("menu_admin"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_common->menuAction());
        menubar->addAction(menu_admin->menuAction());
        menu_common->addAction(action_alterPwd);
        menu_common->addAction(action_logOut);
        menu_common->addAction(action_exit);
        menu_admin->addAction(action_accountProc);

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_alterPwd->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201(&M)", 0));
        action_alterPwd->setShortcut(QApplication::translate("MainWindow", "Alt+M", 0));
        action_logOut->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200(&L)", 0));
        action_logOut->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", 0));
        action_exit->setShortcut(QApplication::translate("MainWindow", "Alt+X", 0));
        action_accountProc->setText(QApplication::translate("MainWindow", "\350\264\246\346\210\267\345\244\204\347\220\206(&A)", 0));
        action_accountProc->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        label_dep->setText(QApplication::translate("MainWindow", "\345\247\213\345\217\221(\344\270\211\345\255\227\347\240\201):", 0));
        label_arr->setText(QApplication::translate("MainWindow", "\345\210\260\350\276\276(\344\270\211\345\255\227\347\240\201):", 0));
        label_policyNo->setText(QApplication::translate("MainWindow", "\346\224\277\347\255\226\344\273\243\347\240\201:", 0));
        label_supplierCode->setText(QApplication::translate("MainWindow", "Office\345\217\267:", 0));
        label_LTT->setText(QApplication::translate("MainWindow", "\346\234\200\346\231\232\346\217\220\345\211\215\345\207\272\347\245\250:", 0));
        label_memo->setText(QApplication::translate("MainWindow", "\347\245\250\345\212\241\350\257\264\346\230\216:", 0));
        patCheck->setText(QApplication::translate("MainWindow", "PAT", 0));
        pnrCheck->setText(QApplication::translate("MainWindow", "pnr", 0));
        itineraryCheck->setText(QApplication::translate("MainWindow", "\350\241\214\347\250\213\345\215\225", 0));
        payCheck->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230", 0));
        rateGtCheck->setText(QApplication::translate("MainWindow", "\350\277\224\347\202\271>", 0));
        rateLtCheck->setText(QApplication::translate("MainWindow", "\350\277\224\347\202\271<", 0));
        label_moneyKeep->setText(QApplication::translate("MainWindow", "\347\225\231\351\222\261:", 0));
        queryButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0));
        dumpButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\344\277\235\345\255\230", 0));
        dumpUpload->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\344\277\235\345\255\230\345\271\266\350\207\252\345\212\250\344\270\212\344\274\240", 0));
        label_companyCode->setText(QApplication::translate("MainWindow", "\350\210\252\345\217\270(\344\270\244\345\255\227\347\240\201):", 0));
        companyCode->setText(QString());
        label_space->setText(QApplication::translate("MainWindow", "\350\210\261\344\275\215:", 0));
        tabs->setTabText(tabs->indexOf(policy), QApplication::translate("MainWindow", "\347\255\233\346\224\277\347\255\226", 0));
        tabs->setTabText(tabs->indexOf(tab_unknown), QApplication::translate("MainWindow", "\345\276\205\346\267\273\345\212\240\345\212\237\350\203\275", 0));
        label_welcome->setText(QString());
        menu_common->setTitle(QApplication::translate("MainWindow", "\346\231\256\351\200\232\347\224\250\346\210\267\350\217\234\345\215\225", 0));
        menu_admin->setTitle(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\350\217\234\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
