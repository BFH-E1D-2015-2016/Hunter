TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    maingame.cpp \
    akterrorist.cpp

RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    BasicLogic.js \
    HolzDeckung.qml \
    main.qml \
    MauerDeckung.qml \
    Reserve.qml \
    Spielbildschirm.qml \
    Startbildschirm.qml \
    SteinDeckung.qml \
    Terrorist1.qml

HEADERS += \
    maingame.h \
    akterrorist.h

