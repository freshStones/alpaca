#-------------------------------------------------
#
# Project created by QtCreator 2014-03-08T05:31:54
#
#-------------------------------------------------

QT       += core gui xml network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
win32{
LIBS += -lWs2_32
}
TARGET = alpaca
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
#    alipay/aliapp.cpp \
#    alipay/hfapp.cpp \
#    ibe/ota_xmlhttp.cpp \
#    ibe/ota_xmlhttp2.cpp \
    Interface_BT/adminwindow.cpp \
    Interface_BT/btdatabase.cpp \
    Interface_BT/dump.cpp \
    Interface_BT/login.cpp \
#    Interface_BT/ota_xmlhttp.cpp \
    Interface_BT/policyOp.cpp \
    Interface_BT/spaceaccount.cpp \
    Interface_BT/gsoap/soapBaitourServiceSoapProxy.cpp \
    Interface_BT/gsoap/soapC.cpp \
    Interface_BT/gsoap/stdsoap2.cpp \
    qunar/qunarpolicyapi.cpp

HEADERS  += mainwindow.h \
#    alipay/aliapp.h \
#    alipay/hfapp.h \
#    ibe/ota_xmlhttp.h \
#    ibe/ota_xmlhttp2.h \
    Interface_BT/adminwindow.h \
    Interface_BT/btdatabase.h \
    Interface_BT/dump.h \
    Interface_BT/login.h \
#    Interface_BT/ota_xmlhttp.h \
    Interface_BT/policyOp.h \
    Interface_BT/spaceaccount.h \
    Interface_BT/gsoap/BaitourServiceSoap.nsmap \
    Interface_BT/gsoap/soapBaitourServiceSoapProxy.h \
    Interface_BT/gsoap/soapH.h \
    Interface_BT/gsoap/soapStub.h \
    Interface_BT/gsoap/stdsoap2.h \
    Interface_BT/gsoap/temp.h \
    qunar/qunarpolicyapi.h

FORMS    += mainwindow.ui \
    Interface_BT/adminwindow.ui \
    Interface_BT/login.ui \
    Interface_BT/mainwindow.ui

RESOURCES += \
    Interface_BT/icon.qrc
