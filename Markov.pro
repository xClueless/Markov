#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T15:32:48
#
#-------------------------------------------------

QT       -= gui

TARGET = Markov
TEMPLATE = lib

CONFIG += c++11

DEFINES += MARKOV_LIBRARY

SOURCES += Markov.cpp \
           MarkovNode.cpp \
           MarkovLink.cpp \
           MarkovHeader.cpp

HEADERS += Markov.hpp\
           markov_global.hpp \
           MarkovNode.hpp \
           MarkovLink.hpp \
           MarkovHeader.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
