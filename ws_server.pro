TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
            "C:\Asio\asio\include"  \
            "C:\Boost\include\boost-1_70"

SOURCES += \
        main.cpp


LIBS += -lws2_32 -lwsock32
