QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balance.cpp \
    cards.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    maketran.cpp \
    transactions.cpp
    balance.cpp \

HEADERS += \
    balance.h \
    cards.h \
    dialog.h \
    mainwindow.h \
    maketran.h \
    transactions.h
    balance.h \

FORMS += \
    balance.ui \
    cards.ui \
    dialog.ui \
    mainwindow.ui \
    maketran.ui \
    transactions.ui

TRANSLATIONS += \
    FinTech_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
