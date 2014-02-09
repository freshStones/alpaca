#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ota_xmlhttp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OTA_XMLHTTP ota_xmlhttp;
    ota_xmlhttp.GetResponse("");
}

MainWindow::~MainWindow()
{
    delete ui;
}
