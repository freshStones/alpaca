#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T11:33:40
#
#-------------------------------------------------

QT       += core
QT       += sql
QT       -= gui
QT       += xml

TARGET = netsale-server
CONFIG   += console
CONFIG   -= app_bundle
win32{
LIBS += -lWs2_32
}
TEMPLATE = app


SOURCES += main.cpp \
    policyOp.cpp \
    gsoapForBaitour/stdsoap2.cpp \
    gsoapForBaitour/soapC.cpp \
    gsoapForBaitour/soapBaitourServiceSoapProxy.cpp \
    sysLog.cpp \
    lhdatabase.cpp

HEADERS += \
    policyOp.h \
    gsoapForBaitour/stdsoap2.h \
    gsoapForBaitour/soapStub.h \
    gsoapForBaitour/soapH.h \
    gsoapForBaitour/soapBaitourServiceSoapProxy.h \
    gsoapForBaitour/BaitourServiceSoap.nsmap \
    gsoapForBaitour/temp.h \
    sysLog.h \
    lhdatabase.h
