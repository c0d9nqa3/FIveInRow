#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T13:37:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug_and_release
CONFIG(debug, debug|release){
    TARGET = ../../_debug/FiveInRow
} else {
    TARGET = ../../_release/FiveInRow
}
TEMPLATE = app


SOURCES += main.cpp\
    begin.cpp \
        mainwindow.cpp \
    Item.cpp

HEADERS  += mainwindow.h \
    Item.h \
    begin.h

FORMS    += mainwindow.ui \
    begin.ui

RC_FILE = app.rc

RESOURCES += \
    picture.qrc
