QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    activerequest.cpp \
    translator.cpp \
    quacktranslator.cpp \
    quack.cpp

RESOURCES += qml.qrc

HEADERS += \
    activerequest.h \
    translator.h \
    quacktranslator.h \
    quack.h
