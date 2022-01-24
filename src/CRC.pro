#-------------------------------------------------
#
# Project created by QtCreator 2022-01-24T10:09:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRC
TEMPLATE = app

RC_ICONS = myicon.ico


SOURCES += main.cpp\
        mainwindow.cpp \
    ModeBusRTU.cpp

HEADERS  += mainwindow.h \
    ModeBusRTU.h

FORMS    += mainwindow.ui
