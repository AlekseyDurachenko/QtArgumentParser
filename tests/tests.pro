TEMPLATE = app
CONFIG += console
QT -= gui
QT += testlib

# enable c++11 features
QMAKE_CXXFLAGS += -std=c++11

include(../qtargumentparser.pri)

INCLUDEPATH +=                                          \
    $$PWD/src                                           \

SOURCES +=                                              \
    $$PWD/src/testmain.cpp                              \
    $$PWD/src/test_qtargumentparserargument.cpp         \
    $$PWD/src/test_qtargumentparserresultrecord.cpp     \
    $$PWD/src/test_qtargumentparserresult.cpp           \
    $$PWD/src/test_qtargumentparser.cpp                 \

HEADERS +=                                              \
    $$PWD/src/test_qtargumentparserargument.h           \
    $$PWD/src/test_qtargumentparserresultrecord.h       \
    $$PWD/src/test_qtargumentparserresult.h             \
    $$PWD/src/test_qtargumentparser.h                   \
