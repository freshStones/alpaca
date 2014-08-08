#-------------------------------------------------
#
# Project created by QtCreator 2013-11-18T08:02:16
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += widgets
QT       += sql
QT       += network
#CONFIG   += qaxcontainer
RC_ICONS = images/icon.ico
ICON = images/icon.icns
TARGET = netsale
TEMPLATE = app

win32{
LIBS += -lWs2_32
}
SOURCES += main.cpp\
        mainwindow.cpp \
    dump.cpp \
    login.cpp \
    adminwindow.cpp \
    spaceaccount.cpp \
    lhdatabase.cpp

HEADERS  += mainwindow.h \
    dump.h \
    login.h \
    adminwindow.h \
    spaceaccount.h \
    lhdatabase.h

FORMS    += \
    mainwindow.ui \
    login.ui \
    adminwindow.ui

OTHER_FILES += \
    gsoap/baitourService.asmx.xml

RESOURCES += \
    icon.qrc
