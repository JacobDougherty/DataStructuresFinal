QT = core
QT       += core gui
QT    += widgets
CONFIG += c++17 cmdline

greaterThan(QT_MAJOR_VERSION, X): QT += widgets
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        addentry.cpp \
        addvehicle.cpp \
        confirm.cpp \
        garage.cpp \
        main.cpp \
        mainwindow.cpp \
        nextreport.cpp \
        report.cpp \
        reportqueue.cpp \
        vehicle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    addentry.h \
    addvehicle.h \
    confirm.h \
    garage.h \
    mainwindow.h \
    nextreport.h \
    report.h \
    reportqueue.h \
    vehicle.h

FORMS += \
    addentry.ui \
    addvehicle.ui \
    confirm.ui \
    mainwindow.ui \
    nextreport.ui

DISTFILES += \
    reportSave.txt \
    vehicleSave.txt
