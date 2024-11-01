QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balance.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp
    balance.cpp \

HEADERS += \
    balance.h \
    dialog.h \
    mainwindow.h
    balance.h \

FORMS += \
    balance.ui \
    dialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    FinTech_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
