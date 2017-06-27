#-------------------------------------------------
#
# Project created by QtCreator 2017-06-19T18:00:22
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StoryCreator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphview.cpp \
    nodeitem.cpp \
    edgeitem.cpp \
    jsonloading.cpp

HEADERS  += mainwindow.hpp \
    graphview.hpp \
    nodeitem.hpp \
    edgeitem.hpp \
    util.hpp \
    graph.hpp \
    jsonloading.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
