QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abuy.cpp \
    achange.cpp \
    addel.cpp \
    adminr.cpp \
    afbuy.cpp \
    asearchg.cpp \
    asearchp.cpp \
    asignin.cpp \
    asignup.cpp \
    edit.cpp \
    finish.cpp \
    main.cpp \
    mainwindow.cpp \
    mbuy.cpp \
    mchange.cpp \
    memberr.cpp \
    mfbuy.cpp \
    msearchg.cpp \
    msearchp.cpp \
    msignin.cpp \
    msignup.cpp

HEADERS += \
    abuy.h \
    achange.h \
    addel.h \
    adminr.h \
    afbuy.h \
    asearchg.h \
    asearchp.h \
    asignin.h \
    asignup.h \
    edit.h \
    finish.h \
    mainwindow.h \
    mbuy.h \
    mchange.h \
    memberr.h \
    mfbuy.h \
    msearchg.h \
    msearchp.h \
    msignin.h \
    msignup.h

FORMS += \
    abuy.ui \
    achange.ui \
    addel.ui \
    adminr.ui \
    afbuy.ui \
    asearchg.ui \
    asearchp.ui \
    asignin.ui \
    asignup.ui \
    edit.ui \
    finish.ui \
    mainwindow.ui \
    mbuy.ui \
    mchange.ui \
    memberr.ui \
    mfbuy.ui \
    msearchg.ui \
    msearchp.ui \
    msignin.ui \
    msignup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
