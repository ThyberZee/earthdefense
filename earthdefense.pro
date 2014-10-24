#-------------------------------------------------
#
# Project created by QtCreator 2014-10-20T19:40:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = earthdefense
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ship.cpp \
    bullet.cpp \
    gamemodel.cpp

HEADERS  += mainwindow.h \
    gamemodel.h \
    ship.h \
    bullet.h

FORMS    += mainwindow.ui
