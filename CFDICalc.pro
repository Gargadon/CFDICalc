#-------------------------------------------------
#
# Project created by QtCreator 2019-10-07T17:45:17
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = CFDICalc
TEMPLATE = app
VERSION = 2.0.1

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        acerca.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        acerca.h \
        mainwindow.h

FORMS += \
        acerca.ui \
        mainwindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc

win32 {
    LIBS += -lws2_32
    RC_ICONS = musashi_mochi_vvM_icon.ico
}
