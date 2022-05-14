#-------------------------------------------------
#
# Project created by QtCreator 2022-04-23T15:49:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = password
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    softkey.cpp

HEADERS  += mainwindow.h \
    connection.h \
    form.h \
    softkey.h

FORMS    += mainwindow.ui \
    form.ui
