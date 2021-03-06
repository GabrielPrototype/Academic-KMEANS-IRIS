#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T22:24:16
#
#-------------------------------------------------
#  his file is part of KMeans_IRIS.
#
#  KMeans_IRIS is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 2 of the License, or
#  (at your option) any later version.
#
#  KMeans_IRIS is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with KMeans_IRIS.  If not, see <http://www.gnu.org/licenses/>.
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KMeans_IRIS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    irisdata.cpp \
    irisdataitem.cpp \
    kcentroid.cpp

HEADERS += \
        mainwindow.h \
    irisdata.h \
    irisdataitem.h \
    kcentroid.h \
    constants.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res/icon_res.qrc

DISTFILES +=

