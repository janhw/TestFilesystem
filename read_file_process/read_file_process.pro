#-------------------------------------------------
#
# Project created by QtCreator 2014-07-04T10:21:15
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = read_file_process
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += \
    ../readConfig/readconfig.h

SOURCES += main.cpp

LIBS += $$PWD/../bin/Debug/libreadConfig.a

CONFIG(debug, debug|release):{
DESTDIR  = $$PWD/../bin/Debug
}
else:CONFIG(release, debug|release):{
DESTDIR  = $$PWD/../bin/Release
}
