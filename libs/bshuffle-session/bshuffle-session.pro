#-------------------------------------------------
#
# Project created by QtCreator 2011-08-09T15:57:46
#
#-------------------------------------------------

TARGET = bshuffle-session
TEMPLATE = lib

DEFINES += BSHUFFLESESSION_LIBRARY

SOURCES += bsession.cpp

HEADERS += bsession.h\
        bshuffle-session_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEAAB026F
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = bshuffle-session.dll
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
