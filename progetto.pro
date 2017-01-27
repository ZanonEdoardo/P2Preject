#-------------------------------------------------
#
# Project created by QtCreator 2016-01-09T08:41:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P2Projectv2
TEMPLATE = app


SOURCES += \
    controller/clienticontroller.cpp \
    controller/impegnicontroller.cpp \
    graphic/gestionecliente.cpp \
    graphic/mainwindow.cpp \
    graphic/moneyedit.cpp \
    graphic/mydatetimeedit.cpp \
    graphic/mydelegate.cpp \
    graphic/qlistclienteitem.cpp \
    graphic/typecombobox.cpp \
    logic/appuntamento.cpp \
    logic/cliente.cpp \
    logic/impegno.cpp \
    logic/impegnolavorativo.cpp \
    logic/lista.cpp \
    logic/persona.cpp \
    logic/personale.cpp \
    logic/professionista.cpp \
    logic/tempodedicato.cpp \
    logic/vectorday.cpp \
    main.cpp \
    controller/myexception.cpp

HEADERS  += \
    controller/clienticontroller.h \
    controller/impegnicontroller.h \
    graphic/gestionecliente.h \
    graphic/mainwindow.h \
    graphic/moneyedit.h \
    graphic/mydatetimeedit.h \
    graphic/mydelegate.h \
    graphic/qlistclienteitem.h \
    graphic/typecombobox.h \
    logic/appuntamento.h \
    logic/cliente.h \
    logic/impegno.h \
    logic/impegnolavorativo.h \
    logic/lista.h \
    logic/persona.h \
    logic/personale.h \
    logic/professionista.h \
    logic/tempodedicato.h \
    logic/vectorday.h \
    controller/myexception.h

FORMS    +=
