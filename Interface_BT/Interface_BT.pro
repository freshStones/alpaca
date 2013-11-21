#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T08:02:16
#
#-------------------------------------------------

QT       += core gui
QT       += xml

TARGET = Interface_BT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gsoap/soapC.cpp \
    gsoap/soapBaitourServiceSoapProxy.cpp \
    gsoap/stdsoap2.cpp \
    policy_op.cpp

HEADERS  += mainwindow.h \
    policy_op.h

FORMS    += mainwindow.ui
