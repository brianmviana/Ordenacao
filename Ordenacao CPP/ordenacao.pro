TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

#LINUX
LIBS += -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system -lpthread
INCLUDEPATH += /usr/lib/

HEADERS += \
    libs/sortview.h \
    libs/player.h

SOURCES += \
    aluno/Sort.cpp

OTHER_FILES += 
    README.md

