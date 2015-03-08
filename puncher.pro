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

SOURCES += src/main.cpp\
        src/puncher.cpp \
    src/data_raw.cpp \
    src/data.cpp \
    src/edit_dialog.cpp \
    src/database.cpp

HEADERS  += inc/puncher.h \
    inc/data_raw.h \
    inc/data.h \
    inc/edit_dialog.h \
    inc/database.h \
    inc/errcodes.h

FORMS    += ui/puncher.ui \
    ui/data.ui \
    ui/data_raw.ui \
    ui/edit_dialog.ui
