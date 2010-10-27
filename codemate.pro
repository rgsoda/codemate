#-------------------------------------------------
#
# Project created by QtCreator 2010-10-24T21:04:02
#
#-------------------------------------------------

QT       += core gui

TARGET = codemate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    snapopen.cpp

HEADERS  += mainwindow.h \
    snapopen.h

FORMS    +=
LIBS     += -lqscintilla2

RESOURCES +=

OTHER_FILES += \
    codemate.style
