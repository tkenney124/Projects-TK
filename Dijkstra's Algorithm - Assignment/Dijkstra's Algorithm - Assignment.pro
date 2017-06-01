QT += core
QT -= gui

CONFIG += c++11

TARGET = DirectedGraph
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    graph.cpp \
    vertex.cpp \
    edge.cpp

HEADERS += \
    graph.h \
    vertex.h \
    edge.h
