#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ota_xmlhttp.h"
#include "ota_xmlhttp2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    OTA_XMLHTTP ota_xmlhttp;
//    ota_xmlhttp.GetResponse("");

    OTA_XMLHTTP2 *ota_xmlhttp2 = new OTA_XMLHTTP2();
    ota_xmlhttp2->GetResponse("");
}

MainWindow::~MainWindow()
{
    delete ui;
}
