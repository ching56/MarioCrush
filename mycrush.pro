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
    game.cpp \
    result.cpp \
    stone1.cpp \
    stone2.cpp \
    stone3.cpp \
    stone4.cpp

HEADERS  += startscreen.h \
    stone.h \
    game.h \
    result.h \
    stone1.h \
    stone2.h \
    stone3.h \
    stone4.h

FORMS    += startscreen.ui \
    game.ui \
    result.ui
