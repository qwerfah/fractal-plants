#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T19:10:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP_03
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    auxiliarystructures/connection.cpp \
    auxiliarystructures/polygonconnection.cpp \
    auxiliarystructures/triangleconnection.cpp \
    builder/compositebuilder.cpp \
    builder/fractalplantbuilder.cpp \
    builder/psurfacebuilder.cpp \
    command/command.cpp \
    command/drawcommand.cpp \
    command/generatecommand.cpp \
    command/loadcommand.cpp \
    command/rotatecommand.cpp \
    command/scalecommand.cpp \
    command/translatecommand.cpp \
    draw/drawscene.cpp \
    factory/builderfactory.cpp \
    factory/generatorfactory.cpp \
    factory/geometryfactory.cpp \
    factory/transformableobjectfactory.cpp \
    generator/fractalplantgenerator.cpp \
    geometry/edge2d.cpp \
    geometry/point2d.cpp \
    geometry/point3d.cpp \
    interface/widget.cpp \
    loader/fileloader.cpp \
    lyndenmayer/lindenmayer.cpp \
    lyndenmayer/rule.cpp \
    lyndenmayer/symbol.cpp \
    lyndenmayer/utilities.cpp \
    manager/drawmanager.cpp \
    manager/generatemanager.cpp \
    manager/loadmanager.cpp \
    manager/rotatemanager.cpp \
    manager/scalemanager.cpp \
    manager/searchmanager.cpp \
    manager/translatemanager.cpp \
    projection/parallelprojection.cpp \
    transform/FractalPlantCarcassTransformation.cpp \
    transform/polygonsurfacetransformation.cpp \
    transformableobject/camera.cpp \
    transformableobject/compositeobject.cpp \
    transformableobject/cylinder.cpp \
    transformableobject/fractalplantcarcass.cpp \
    transformableobject/polygonsurface.cpp \
    baseclass.cpp \
    main.cpp \
    mainscene.cpp \
    light/pointlight.cpp \
    generator/fractalplantenerateoptions.cpp




HEADERS += \
    auxiliarystructures/auxiliarystructure.h \
    auxiliarystructures/connection.h \
    auxiliarystructures/polygonconnection.h \
    auxiliarystructures/triangleconnection.h \
    builder/builder.h \
    builder/compositebuilder.h \
    builder/fractalplantbuilder.h \
    builder/psurfacebuilder.h \
    command/command.h \
    command/drawcommand.h \
    command/generatecommand.h \
    command/loadcommand.h \
    command/rotatecommand.h \
    command/scalecommand.h \
    command/translatecommand.h \
    draw/drawscene.h \
    factory/builderfactory.h \
    factory/factory.h \
    factory/generatorfactory.h \
    factory/geometryfactory.h \
    factory/transformableobjectfactory.h \
    generator/fractalplantgenerator.h \
    generator/generateoptions.h \
    generator/generator.h \
    geometry/edge2d.h \
    geometry/geometryprimitive.h \
    geometry/point2d.h \
    geometry/point3d.h \
    interface/qtwindow.h \
    interface/widget.h \
    interface/window.h \
    interface/windowimpl.h \
    loader/fileloader.h \
    loader/loader.h \
    lyndenmayer/lindenmayer.h \
    lyndenmayer/rule.h \
    lyndenmayer/symbol.h \
    lyndenmayer/utilities.h \
    manager/drawmanager.h \
    manager/generatemanager.h \
    manager/loadmanager.h \
    manager/manager.h \
    manager/rotatemanager.h \
    manager/scalemanager.h \
    manager/searchmanager.h \
    manager/transformmanager.h \
    manager/translatemanager.h \
    projection/parallelprojection.h \
    projection/projection.h \
    transform/FractalPlantCarcassTransformation.h \
    transform/polygonsurfacetransformation.h \
    transform/transformations.h \
    transformableobject/compositeobject.h \
    transformableobject/cylinder.h \
    transformableobject/fractalplantcarcass.h \
    transformableobject/polygonsurface.h \
    transformableobject/staticcamera.h \
    transformableobject/transformableobject.h \
    baseclass.h \
    enums.h \
    exceptions.h \
    mainscene.h \
    position.h \
    sort.h \
    sortprotected.h \
    transformableobject/camera.h \
    light/light.h \
    light/pointlight.h \
    generator/fractalplantgenerateoptions.h






FORMS += \
        widget.ui
