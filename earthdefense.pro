#-------------------------------------------------
#
# Project created by QtCreator 2014-10-20T19:40:51
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++0x # Singleton

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = earthdefense
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        highscore.cpp \
        gamemodel.cpp \
        worldentity.cpp

HEADERS  += mainwindow.h \
            gamemodel.h \
            highscore.h \
            worldentity.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
