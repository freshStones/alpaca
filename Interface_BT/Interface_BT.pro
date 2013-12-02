#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T08:02:16
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += widgets
QT       += sql
#CONFIG   += qaxcontainer

TARGET = Interface_BT
TEMPLATE = app

win32{
LIBS += -lWs2_32
}
SOURCES += main.cpp\
        mainwindow.cpp \
    gsoap/soapC.cpp \
    gsoap/soapBaitourServiceSoapProxy.cpp \
    gsoap/stdsoap2.cpp \
    policyOp.cpp \
    btdatabase.cpp \
    dump.cpp \
    login.cpp \
    adminwindow.cpp

HEADERS  += mainwindow.h \
    gsoap/temp.h \
    gsoap/stdsoap2.h \
    gsoap/soapStub.h \
    gsoap/soapH.h \
    gsoap/soapBaitourServiceSoapProxy.h \
    gsoap/BaitourServiceSoap.nsmap \
    policyOp.h \
    btdatabase.h \
    dump.h \
    login.h \
    adminwindow.h

FORMS    += \
    mainwindow.ui \
    login.ui \
    adminwindow.ui

OTHER_FILES += \
    gsoap/baitourService.asmx.xml
