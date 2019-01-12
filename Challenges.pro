#-------------------------------------------------
#
# Project created by QtCreator 2018-12-26T21:19:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Challanges
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include
#DEFINES += CONFIG_STARFIELD_MODULE
DEFINES += CONFIG_SNAKE_MODULE

SOURCES += src/main.cpp\
        src/window.cpp \
    challenges/snake/engine.cpp

HEADERS  += include/window.h \
    include/snake/field.h \
    include/snake/engine.h

contains(DEFINES, CONFIG_STARFIELD_MODULE)
{
    SOURCES += challenges/starfield/starfield.cpp
    HEADERS += include/starfield.h
}

contains(DEFINES, CONFIG_SNAKE_MODULE)
{
    SOURCES += challenges/snake/field.cpp
    HEADERS += include/snake/field.h
}
