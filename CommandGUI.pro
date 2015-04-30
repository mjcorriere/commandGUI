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
    commandfactory.cpp \
    boomcommand.cpp

HEADERS  += commandgui.h \
    commandfactory.h \
    echocommand.h \
    waitcommand.h \
    icommand.h \
    boomcommand.h

FORMS    += commandgui.ui
