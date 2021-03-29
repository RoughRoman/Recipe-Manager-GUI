QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+= static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RecipeManager.cpp \
    addingredientdialog.cpp \
    addrecipedialog.cpp \
    choicedialog.cpp \
    ingredient.cpp \
    main.cpp \
    mainwindow.cpp \
    messagedialog.cpp \
    recipe.cpp

HEADERS += \
    RecipeManager.hpp \
    addingredientdialog.h \
    addrecipedialog.h \
    choicedialog.h \
    ingredient.hpp \
    mainwindow.h \
    messagedialog.h \
    recipe.hpp

FORMS += \
    addingredientdialog.ui \
    addrecipedialog.ui \
    choicedialog.ui \
    mainwindow.ui \
    messagedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Notes
