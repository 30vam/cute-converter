QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/abstractconverter.cpp \
    src/areaconverter.cpp \
    src/currentconverter.cpp \
    src/energyconverter.cpp \
    src/forceconverter.cpp \
    src/lengthconverter.cpp \
    src/powerconverter.cpp \
    src/pressureconverter.cpp \
    src/speedconverter.cpp \
    src/temperatureconverter.cpp \
    src/timeconverter.cpp \
    src/volumeconverter.cpp \
    src/weightconverter.cpp

HEADERS += \
    mainwindow.h \
    src/abstractconverter.h \
    src/areaconverter.h \
    src/currentconverter.h \
    src/energyconverter.h \
    src/forceconverter.h \
    src/lengthconverter.h \
    src/powerconverter.h \
    src/pressureconverter.h \
    src/speedconverter.h \
    src/temperatureconverter.h \
    src/timeconverter.h \
    src/volumeconverter.h \
    src/weightconverter.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    qt-unit-converter_fa_IR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
