QT       += core gui svg multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

TARGET = ui
TEMPLATE = app

include(gui/gui.pri)
include(model/model.pri)
include(common/common.pri)
include(svgdialgauge/svgdialgauge.pri)
include(svgbutton/svgbutton.pri)
include(svgslideswitch/svgslideswitch.pri)
include(KeyboardWidget/KeyboardWidget.pri)
include(PasswordWidget/PasswordWidget.pri)

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += resources/resources.qrc

