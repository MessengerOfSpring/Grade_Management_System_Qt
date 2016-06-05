#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T14:35:03
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpp-project
TEMPLATE = app


SOURCES += main.cpp\
        LoginDlg.cpp \
    Check.cpp \
    StudentMainWindow.cpp \
    AdminMainWindow.cpp \
    Grade.cpp \
    FindDlg.cpp \
    EditDlg.cpp \
    AddDlg.cpp

HEADERS  += LoginDlg.h \
    Check.h \
    StudentMainWindow.h \
    AdminMainWindow.h \
    Grade.h \
    FindDlg.h \
    EditDlg.h \
    AddDlg.h

FORMS    += LoginDlg.ui \
    StudentMainWindow.ui \
    AdminMainWindow.ui \
    FindDlg.ui \
    EditDlg.ui \
    AddDlg.ui

RC_FILE += ico.rc \
