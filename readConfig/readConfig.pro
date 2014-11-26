#-------------------------------------------------
#
# Project created by QtCreator 2014-07-05T10:07:25
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = readConfig
CONFIG += staticlib

TEMPLATE = lib


#SOURCES += main.cpp \
SOURCES += readconfig.cpp

HEADERS += \
    readconfig.h

CONFIG(debug, debug|release):{
DESTDIR  = $$PWD/../bin/Debug
}
else:CONFIG(release, debug|release):{
DESTDIR  = $$PWD/../bin/Release
}
