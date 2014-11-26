#-------------------------------------------------
#
# Project created by QtCreator 2014-07-03T15:14:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = write_file_process
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
