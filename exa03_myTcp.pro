#-------------------------------------------------
#
# Project created by QtCreator 2017-03-17T13:25:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = exa03_myTcp
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    myhttp.cpp \
    mysocket.cpp \
    myhex.cpp \
    myrtcm.cpp \
    myrtcm3.cpp \
    myrtcm1004.cpp

QT += network

HEADERS += \
    myhttp.h \
    mysocket.h \
    myhex.h \
    myrtcm.h \
    myhead.h \
    myrtcm3.h \
    myrtcm1004.h

