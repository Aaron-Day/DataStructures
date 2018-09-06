CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += \
    ../../CST211/Assignment3/main.cpp


QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

# QMAKE_CXXFLAGS += -Werror
# QMAKE_CXXFLAGS += -Wno-error=unused-variable

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    ../../CST211/Assignment3/driver.h \
    ../../CST211/Assignment3/iterator.h \
    ../../CST211/Assignment3/iterator.inc \
    ../../CST211/Assignment3/linkedlist.h \
    ../../CST211/Assignment3/linkedlist.inc \
    ../../CST211/Assignment3/node.h \
    ../../CST211/Assignment3/node.inc


