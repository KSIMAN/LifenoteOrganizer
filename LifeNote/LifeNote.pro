QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QMAKE_CXXFLAGS_RELEASE+=-O0
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    diarycontroller.cpp \
    diaryform.cpp \
    guithemes.cpp \
    main.cpp \
    mainwindow.cpp \
    noteclass.cpp \
    noteeditor.cpp \
    noteform.cpp \
    tdlitem.cpp \
    todoform.cpp

HEADERS += \
    diarycontroller.h \
    diaryform.h \
    guithemes.h \
    includes.h \
    mainwindow.h \
    noteclass.h \
    noteeditor.h \
    noteform.h \
    tdlitem.h \
    todoform.h

FORMS += \
    diaryform.ui \
    mainwindow.ui \
    noteeditor.ui \
    noteform.ui \
    tdlitem.ui \
    todoform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
