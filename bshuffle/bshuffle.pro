#-------------------------------------------------
#
# Project created by QtCreator 2011-06-10T14:59:43
#
#-------------------------------------------------

QT       += core gui

TARGET = bshuffle
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/aboutdialog.cpp \
    src/groupsdialog.cpp

HEADERS  += src/mainwindow.h \
    src/aboutdialog.h \
    src/groupsdialog.h

FORMS    += forms/mainwindow.ui \
    forms/aboutdialog.ui \
    forms/groupsdialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/bshuffle-session/release/ -lbshuffle-session
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/bshuffle-session/debug/ -lbshuffle-session
else:symbian: LIBS += -lbshuffle-session
else:unix: LIBS += -L$$OUT_PWD/../libs/bshuffle-session/ -lbshuffle-session

INCLUDEPATH += $$PWD/../libs/bshuffle-session
DEPENDPATH += $$PWD/../libs/bshuffle-session

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/print-settings/release/ -lprint-settings
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/print-settings/debug/ -lprint-settings
else:symbian: LIBS += -lprint-settings
else:unix: LIBS += -L$$OUT_PWD/../libs/print-settings/ -lprint-settings

INCLUDEPATH += $$PWD/../libs/print-settings
DEPENDPATH += $$PWD/../libs/print-settings
