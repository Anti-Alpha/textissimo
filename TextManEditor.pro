#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T20:33:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextManEditor
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    htmlsyntaxhighlighter.cpp \
    patterns.cpp

HEADERS += \
        mainwindow.h \
    htmlsyntaxhighlighter.h \
    patterns.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    iconresource.qrc

