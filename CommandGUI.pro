#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T18:44:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CommandGUI
TEMPLATE = app


SOURCES += main.cpp\
        commandgui.cpp \
    echocommand.cpp \
    waitcommand.cpp \
    commandfactory.cpp

HEADERS  += commandgui.h \
    command.h \
    commandfactory.h \
    echocommand.h \
    waitcommand.h

FORMS    += commandgui.ui
