QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Arc.cpp \
    Attdef.cpp \
    Attrib.cpp \
    Block.cpp \
    Blocks.cpp \
    Circle.cpp \
    Dimension.cpp \
    DxfObject.cpp \
    Entities.cpp \
    Entity.cpp \
    Entry.cpp \
    Face3d.cpp \
    Header.cpp \
    Insert.cpp \
    Layer.cpp \
    LayerTable.cpp \
    Line.cpp \
    Line3d.cpp \
    LineType.cpp \
    LineTypeTable.cpp \
    Point.cpp \
    Point3d.cpp \
    Polyline.cpp \
    Section.cpp \
    Shape.cpp \
    Solid.cpp \
    Style.cpp \
    StyleTable.cpp \
    Table.cpp \
    Tables.cpp \
    Text.cpp \
    Tokenizer.cpp \
    Trace.cpp \
    Translator.cpp \
    Ucs.cpp \
    UcsTable.cpp \
    Vertex.cpp \
    View.cpp \
    ViewTable.cpp \
    Vport.cpp \
    VportTable.cpp \
    arcgraphicsitem.cpp \
    biesseprogramm.cpp \
    circlegraphicsitem.cpp \
    graphicsitem.cpp \
    linegraphicsitem.cpp \
    main.cpp \
    mainwindow.cpp \
    paneldialog.cpp

HEADERS += \
    Arc.h \
    Attdef.h \
    Attrib.h \
    Block.h \
    Blocks.h \
    Circle.h \
    Dimension.h \
    DxfObject.h \
    Entities.h \
    Entity.h \
    Entry.h \
    Face3d.h \
    Header.h \
    Insert.h \
    Layer.h \
    LayerTable.h \
    Line.h \
    Line3d.h \
    LineType.h \
    LineTypeTable.h \
    Point.h \
    Point3d.h \
    Polyline.h \
    Section.h \
    Shape.h \
    Solid.h \
    Style.h \
    StyleTable.h \
    Table.h \
    Tables.h \
    Text.h \
    Tokenizer.h \
    Trace.h \
    Translator.h \
    Ucs.h \
    UcsTable.h \
    Vertex.h \
    View.h \
    ViewTable.h \
    Vport.h \
    VportTable.h \
    arcgraphicsitem.h \
    biesseprogramm.h \
    circlegraphicsitem.h \
    graphicsitem.h \
    linegraphicsitem.h \
    mainwindow.h \
    paneldialog.h \
    tcl_dxf_defs.h

FORMS += \
    mainwindow.ui \
    paneldialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    BiesseBpp.pro.user

