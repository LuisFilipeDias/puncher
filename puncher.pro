#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T22:13:45
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puncher
TEMPLATE = app

#DEFINES += DB_debug

SOURCES += main.cpp\
        puncher.cpp \
    data_raw.cpp \
    data.cpp \
    edit_dialog.cpp

HEADERS  += puncher.h \
    data_raw.h \
    data.h \
    edit_dialog.h

FORMS    += puncher.ui \
    data.ui \
    data_raw.ui \
    edit_dialog.ui
