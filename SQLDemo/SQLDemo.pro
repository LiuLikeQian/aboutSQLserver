#-------------------------------------------------
#
# Project created by QtCreator 2015-12-27T20:11:22
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQLDemo
TEMPLATE = app


SOURCES += main.cpp\
        sqldemo.cpp \
    homepage.cpp \
    modifyinfo.cpp \
    deleteinfo.cpp \
    adduser.cpp \
    queryuser.cpp \
    userpay.cpp \
    userwidget.cpp

HEADERS  += sqldemo.h \
    homepage.h \
    modifyinfo.h \
    deleteinfo.h \
    adduser.h \
    queryuser.h \
    userpay.h \
    userwidget.h

FORMS    += sqldemo.ui \
    homepage.ui \
    modifyinfo.ui \
    deleteinfo.ui \
    adduser.ui \
    queryuser.ui \
    userpay.ui \
    userwidget.ui

RESOURCES += \
    image.qrc
RC_FILE = sqlphone.rc
