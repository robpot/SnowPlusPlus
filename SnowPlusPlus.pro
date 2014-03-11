#-------------------------------------------------
#
# Project created by QtCreator 2014-03-04T15:53:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnowPlusPlus
TEMPLATE = app


SOURCES += src\main.cpp\
    src/snowPlusPlus.cpp \
    src/dropZone.cpp \
    src/codeFrame.cpp \
    src/codeBlock.cpp \
    src/blockPalette.cpp \
    src/application.cpp \
    src/animationFrame.cpp \
    src/messageBox.cpp \
    src/snowman.cpp \
    src/scorebox.cpp \
    src/backdrop.cpp \
    src/dragStorage.cpp


HEADERS  += src/snowPlusPlus.h \
    src/dropZone.h \
    src/codeFrame.h \
    src/codeBlock.h \
    src/blockPalette.h \
    src/application.h \
    src/animationFrame.h \
    src/messageBox.h \
    src/snowman.h \
    src/scorebox.h \
    src/backdrop.h \
    src/dragStorage.h

RESOURCES += \
    resources.qrc
