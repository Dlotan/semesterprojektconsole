#-------------------------------------------------
#
# Project created by QtCreator 2015-01-25T20:00:50
#
#-------------------------------------------------

QT       += core
QT       += sql
QT       -= gui

TARGET = semesterprojektconsole
CONFIG   += console
CONFIG   += c++11
CONFIG   -= app_bundle

TEMPLATE = app

include(generator/generator.pri)
include(database/database.pri)

SOURCES += main.cpp \
    dicemaster.cpp \
    randomrangeclass.cpp \
    filemanager.cpp

HEADERS += \
    dicemaster.h \
    randomrangeclass.h \
    filemanager.h
