# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.

TEMPLATE = lib
TARGET = lomox
DESTDIR = ../Release
QT += core gui sql network xml webkit
CONFIG += debug
DEFINES += QT_LARGEFILE_SUPPORT QT_XML_LIB QT_SQL_LIB QT_NETWORK_LIB QT_WEBKIT_LIB QT_WEBKITWIDGETS_LIB LOMOX_LIB
INCLUDEPATH += ./GeneratedFiles \
    ./GeneratedFiles/Release \
    .
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(lomox.pri)
