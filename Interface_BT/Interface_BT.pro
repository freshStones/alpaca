#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T08:02:16
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += widgets
QT       += sql

TARGET = Interface_BT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gsoap/soapC.cpp \
    gsoap/soapBaitourServiceSoapProxy.cpp \
    gsoap/stdsoap2.cpp \
    policyOp.cpp \
    btdatabase.cpp

HEADERS  += mainwindow.h \
    gsoap/temp.h \
    gsoap/stdsoap2.h \
    gsoap/soapStub.h \
    gsoap/soapH.h \
    gsoap/soapBaitourServiceSoapProxy.h \
    gsoap/BaitourServiceSoap.nsmap \
    policyOp.h \
    btdatabase.h

FORMS    += \
    mainwindow.ui

OTHER_FILES += \
    gsoap/baitourService.asmx.xml
