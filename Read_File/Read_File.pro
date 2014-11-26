#-------------------------------------------------
#
# Project created by QtCreator 2014-07-04T10:11:29
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Read_File
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ../readConfig

TEMPLATE = app

HEADERS += \
    ../readConfig/readconfig.h

SOURCES += main.cpp\

LIBS += $$PWD/../bin/Debug/libreadConfig.a

CONFIG(debug, debug|release):{
DESTDIR  = $$PWD/../bin/Debug
}
else:CONFIG(release, debug|release):{
DESTDIR  = $$PWD/../bin/Release
}
