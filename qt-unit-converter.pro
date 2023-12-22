QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    searchdialog.cpp \
    src/abstractconverter.cpp \
    src/angleconverter.cpp \
    src/areaconverter.cpp \
    src/concentrationconverter.cpp \
    src/currentconverter.cpp \
    src/datastorageconverter.cpp \
    src/densityconverter.cpp \
    src/energyconverter.cpp \
    src/forceconverter.cpp \
    src/fuelconsumptionconverter.cpp \
    src/lengthconverter.cpp \
    src/luminanceconverter.cpp \
    src/magneticfluxdensityconverter.cpp \
    src/powerconverter.cpp \
    src/pressureconverter.cpp \
    src/speedconverter.cpp \
    src/temperatureconverter.cpp \
    src/timeconverter.cpp \
    src/torqueconverter.cpp \
    src/viscosityconverter.cpp \
    src/voltageconverter.cpp \
    src/volumeconverter.cpp \
    src/volumetricflowrateconverter.cpp \
    src/weightconverter.cpp

HEADERS += \
    aboutdialog.h \
    mainwindow.h \
    searchdialog.h \
    src/abstractconverter.h \
    src/angleconverter.h \
    src/areaconverter.h \
    src/concentrationconverter.h \
    src/currentconverter.h \
    src/datastorageconverter.h \
    src/densityconverter.h \
    src/energyconverter.h \
    src/forceconverter.h \
    src/fuelconsumptionconverter.h \
    src/lengthconverter.h \
    src/luminanceconverter.h \
    src/magneticfluxdensityconverter.h \
    src/powerconverter.h \
    src/pressureconverter.h \
    src/speedconverter.h \
    src/temperatureconverter.h \
    src/timeconverter.h \
    src/torqueconverter.h \
    src/viscosityconverter.h \
    src/voltageconverter.h \
    src/volumeconverter.h \
    src/volumetricflowrateconverter.h \
    src/weightconverter.h

FORMS += \
    aboutdialog.ui \
    mainwindow.ui \
    searchdialog.ui

TRANSLATIONS += \
    qt-unit-converter_fa_IR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    fonts.qrc \
    icons.qrc \
    stylesheets/stylesheets.qrc
