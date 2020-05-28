TEMPLATE = subdirs
# build the project sequentially as listed in SUBDIRS
CONFIG+= ordered

SUBDIRS += \
    src \
    app \ \
    tests

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
