#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T22:13:45
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puncher
TEMPLATE = app


SOURCES += main.cpp\
        puncher.cpp \
    data.cpp \
    data_raw.cpp

HEADERS  += puncher.h \
    data.h \
    data_raw.h

FORMS    += puncher.ui \
    data.ui \
    data_raw.ui
