#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T20:15:50
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QTPLUGIN   += qjpeg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widmowy
TEMPLATE = app




SOURCES += main.cpp\
        mainwindow.cpp \
    ekran.cpp

HEADERS  += mainwindow.h \
    ekran.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc
