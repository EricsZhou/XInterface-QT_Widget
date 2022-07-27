QT       += core gui
QT       += websockets
QT  += opengl
QT       += openglwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT -= gui
CONFIG += c++11
LIBS +=-lopengl32 -lglu32
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bigsreenform.cpp \
    configdata.cpp \
    djwidget.cpp \
    glspoutimagewidget.cpp\
    glwidget.cpp\
    main.cpp \
    mymouseqlabel.cpp\
    qchdbghelp.cpp \
    scenchangform.cpp \
    scenchangwidget.cpp \
    server.cpp \
    switchwidget.cpp \
    tcp.cpp

HEADERS += \
    MyButton.h \
    bigsreenform.h \
    configdata.h \
    djwidget.h \
    glspoutimagewidget.h\
    mymouseqlabel.h\
    glwidget.h\
    qchdbghelp.h \
    scenchangform.h \
    scenchangwidget.h \
    server.h \
    switchwidget.h \
    tcp.h

FORMS += \
    tcp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    Photo.qrc

##release版本可调试
QMAKE_CXXFLAGS_RELEASE += $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
##release版也将生成“.pdb”后缀的调试信息文件
QMAKE_LFLAGS_RELEASE = /INCREMENTAL:NO /DEBUG
#调用库
LIBS += -lDbgHelp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SpoutGL/VS2017/x64/release/ -lSpout
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SpoutGL/VS2017/x64/debug/ -lSpout

INCLUDEPATH += $$PWD/SpoutGL/VS2017/x64/Release
DEPENDPATH += $$PWD/SpoutGL/VS2017/x64/Release

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/SpoutGL/VS2017/x64/release/libSpout.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/SpoutGL/VS2017/x64/debug/libSpout.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/SpoutGL/VS2017/x64/release/Spout.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/SpoutGL/VS2017/x64/debug/Spout.lib
