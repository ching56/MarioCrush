#-------------------------------------------------
#
# Project created by QtCreator 2015-06-08T10:11:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mycrush
TEMPLATE = app


SOURCES += main.cpp\
        startscreen.cpp \
    stone.cpp \
    result.cpp \
    game.cpp

HEADERS  += startscreen.h \
    stone.h \
    result.h \
    game.h

FORMS    += startscreen.ui \
    game.ui
