QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console

INCLUDEPATH += inc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/process.cpp \
    src/work_with_data.cpp \
    src/utils.cpp \
    src/maindrawer.cpp \
    src/main_func.cpp \
    src/read_data.cpp \
    src/validate_data.cpp

HEADERS += \
    inc/mainwindow.h \
    inc/process.h \
    inc/struct.h \
    inc/errors.h \
    inc/work_with_data.h \
    inc/utils.h \
    inc/maindrawer.h \
    inc/main_func.h \
    inc/read_data.h \
    inc/validate_data.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
