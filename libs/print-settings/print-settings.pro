#-------------------------------------------------
#
# Project created by QtCreator 2011-08-09T16:26:38
#
#-------------------------------------------------

QT       -= gui

TARGET = print-settings
TEMPLATE = lib

DEFINES += PRINTSETTINGS_LIBRARY

SOURCES += printsettings.cpp

HEADERS += printsettings.h\
        print-settings_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE5FAE7AB
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = print-settings.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
