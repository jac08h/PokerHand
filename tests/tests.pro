include(../defaults.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    catch2.h


LIBS += -L../src  -lmyapp
