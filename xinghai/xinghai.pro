#-------------------------------------------------
#
# Project created by QtCreator 2014-04-13T11:49:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = xinghai
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    gsoap/soapC.cpp \
    gsoap/soapBasicHttpBinding_USCOREixinghaiProxy.cpp \
    gsoap/stdsoap2.cpp \
    xhhotel.cpp

HEADERS += \
    gsoap/soapStub.h \
    gsoap/soapH.h \
    gsoap/soapBasicHttpBinding_USCOREixinghaiProxy.h \
    gsoap/stdsoap2.h \
    xhhotel.h
