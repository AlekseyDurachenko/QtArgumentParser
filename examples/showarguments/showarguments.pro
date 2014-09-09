TEMPLATE = app
CONFIG += console
QT -= gui

include(../../qtargumentparser.pri)

INCLUDEPATH +=                              \
    src                                     \

SOURCES +=                                  \
    src/main.cpp                            \

HEADERS +=                                  \
