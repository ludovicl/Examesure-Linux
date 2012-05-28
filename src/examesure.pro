TEMPLATE = app
TARGET =
DEPENDPATH += .
INCLUDEPATH += .
HEADERS += camera.h \
 etalonnage.h \
 four.h \
 mainwindow.h \
 rs232.h \
 sonde.h \
    config.h
FORMS += mainwindow.ui \
    config.ui
SOURCES += camera.cpp \
 etalonnage.cpp \
 four.cpp \
 main.cpp \
 mainwindow.cpp \
 rs232.cpp \
 sonde.cpp \
    config.cpp
CONFIG += link_pkgconfig
PKGCONFIG = opencv
