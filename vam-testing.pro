#-------------------------------------------------
#
# Project created by QtCreator 2012-05-11T10:46:44
#
#-------------------------------------------------

QT       += core gui

TARGET = vam-testing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    intensity.cpp \
    color_feature.cpp \
    orientation_feature.cpp \
    saliency.cpp \
    winnertakeall.cpp \
    classifier.cpp \
    template.cpp

HEADERS  += mainwindow.h \
    initial_variables.h \
    intensity.h \
    color_feature.h \
    orientation_feature.h \
    saliency.h \
    winnertakeall.h \
    classifier.h \
    template.h

FORMS    += mainwindow.ui

CONFIG += link_pkgconfig
PKGCONFIG += opencv
