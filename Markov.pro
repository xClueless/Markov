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

SOURCES += MarkovNode.cpp \
           MarkovLink.cpp \
           MarkovHeader.cpp \
           MarkovChain.cpp

HEADERS += markov_global.hpp \
           MarkovNode.hpp \
           MarkovLink.hpp \
           MarkovHeader.hpp \
           MarkovChain.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
