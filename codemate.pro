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
    snapopen.cpp \
    mateeditor.cpp \
    snippeteditor.cpp \
    buffercompletionengine.cpp \
    completebinding.cpp


HEADERS  += mainwindow.h \
    snapopen.h \
    mateeditor.h \
    snippeteditor.h \
    buffercompletionengine.h \
    completebinding.h


FORMS    +=
LIBS     += -L. -lqcodeedit

RESOURCES +=

OTHER_FILES += \
    codemate.style
DEPENDPATH += . qce
INCLUDEPATH += . qce

DEPENDPATH += . qce/document qce/language qce/widgets qce/qnfa
INCLUDEPATH += . qce/document qce/language qce/widgets qce/qnfa

SUBDIRS = qce
