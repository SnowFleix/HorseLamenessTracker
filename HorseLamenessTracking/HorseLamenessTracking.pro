QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    configurationpage.cpp \
    filehandler.cpp \
    graphicsworker.cpp \
    main.cpp \
    homewindow.cpp \
    resultspage.cpp \
    trackingpage.cpp \
    trackingworker.cpp \
    utilfunctions.cpp

HEADERS += \
    configurationpage.h \
    definitions.h \
    filehandler.h \
    graphicsworker.h \
    homewindow.h \
    marker.h \
    movingaverage.h \
    resultspage.h \
    trackingpage.h \
    trackingworker.h \
    utilfunctions.h

FORMS += \
    configurationpage.ui \
    homewindow.ui \
    resultspage.ui \
    trackingpage.ui

TRANSLATIONS += \
    HorseLamenessTracking_en_GB.ts

INCLUDEPATH += J:\opencv-4.3.0\opencv\build\include

LIBS += J:\OpenCV\opencv\build\x64\vc15\lib\opencv_world411d.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
