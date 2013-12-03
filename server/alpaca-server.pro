#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T11:33:40
#
#-------------------------------------------------

QT       += core
QT       += sql
QT       -= gui
QT       += xml

TARGET = alpaca-server
CONFIG   += console
CONFIG   -= app_bundle
win32{
LIBS += -lWs2_32
}
TEMPLATE = app


SOURCES += main.cpp \
    policyOp.cpp \
    btdatabase.cpp \
    gsoap/stdsoap2.cpp \
    gsoap/soapC.cpp \
    gsoap/soapBaitourServiceSoapProxy.cpp

HEADERS += \
    policyOp.h \
    btdatabase.h \
    gsoap/stdsoap2.h \
    gsoap/soapStub.h \
    gsoap/soapH.h \
    gsoap/soapBaitourServiceSoapProxy.h \
    gsoap/BaitourServiceSoap.nsmap \
    gsoap/temp.h
