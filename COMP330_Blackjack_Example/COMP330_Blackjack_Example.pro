QT += core
QT -= gui

CONFIG += c++11

TARGET = COMP330_Blackjack_Example
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dealer.cpp \
    player.cpp \
    card.cpp \
    deck.cpp

HEADERS += \
    dealer.h \
    player.h \
    card.h \
    deck.h
