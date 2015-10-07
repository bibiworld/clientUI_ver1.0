#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T22:07:27
#
#-------------------------------------------------

QT       += core gui
QT += network
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    search.cpp \
    login.cpp \
    cards.cpp \
    fuzzysearch.cpp

HEADERS  += mainwindow.h \
    search.h \
    login.h \
    cards.h \
    fuzzysearch.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
