#-------------------------------------------------
#
# Project created by QtCreator 2018-01-05T21:40:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = major-project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    verification.cpp \
    searching.cpp \
    preprocessing.cpp

HEADERS  += mainwindow.h \
    verification.h \
    searching.h \
    preprocessing.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$_PRO_FILE_PWD_
