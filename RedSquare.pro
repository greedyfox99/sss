QT += quick quickcontrols2

CONFIG += c++11
msvc {
    QMAKE_CXXFLAGS += /utf-8
}


SOURCES += \
        backend.cpp \
        main.cpp

RESOURCES += qml.qrc



INCLUDEPATH +="D:/test"
LIBS +=-L "D:/test" -lmytest


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    RedSquare.qml

HEADERS += \
    backend.h

# 打印一下编译器的信息，看看你现在的配置
#message("当前编译器配置: " $$QMAKE_CXX)
message("Current config: " $$QMAKE_CXX)



