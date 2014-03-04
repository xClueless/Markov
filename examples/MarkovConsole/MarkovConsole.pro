#-------------------------------------------------
#
# Project created by QtCreator 2014-03-03T20:52:11
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MarkovConsole
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH+=/usr/local/include
LIBS += -lqmarkov


SOURCES += main.cpp
