QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 second_main

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    calculator.cpp \
    credits.cpp \
    deposit.cpp \
    main.cpp \
    model.cc \
    qcustomplot.cpp \
    view.cpp

HEADERS += \
    controller.h \
    calculator.h \
    credits.h \
    deposit.h \
    model.h \
    qcustomplot.h \
    view.h

FORMS += \
    calculator.ui \
    credits.ui \
    deposit.ui

second_main {
    SOURCES += \
        tests.cc \
        model.cc
    HEADERS += model.h
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
