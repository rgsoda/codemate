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
    codeeditor.cpp \
    highlighter.cpp

HEADERS  += mainwindow.h \
    codeeditor.h \
    highlighter.h

FORMS    += mainwindow.ui
LIBS     += -lqscintilla2
