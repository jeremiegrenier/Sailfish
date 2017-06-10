# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = DictatorWorld

CONFIG += sailfishapp

SOURCES += src/DictatorWorld.cpp \
    src/Pays.cpp \
    src/Countries.cpp \
    src/Question.cpp \
    src/Questions.cpp

OTHER_FILES += qml/DictatorWorld.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/DictatorWorld.changes.in \
    rpm/DictatorWorld.spec \
    rpm/DictatorWorld.yaml \
    translations/*.ts \
    DictatorWorld.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

#TODO: icon
RC_ICONS = qrc:///resources/picture/couronne.png

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/DictatorWorld-de.ts

DISTFILES += \
    qml/resources/picture/allemagne.png \
    qml/resources/picture/france.ico \
    qml/resources/picture/russie.png \
    qml/resources/picture/italie.png \
    qml/resources/picture/espagne.png \
    qml/resources/picture/belgique.png \
    qml/resources/picture/angleterre.png \
    qml/resources/picture/etats-unis.png \
    qml/pages/SurveyPage.qml \
    qml/component/CountryFlag.qml \
    qml/pages/CountryFlag.qml \
    qml/resources/picture/couronne.png \
    qml/pages/Question.qml \
    qml/resources/picture/notFound.png

HEADERS += \
    src/Pays.h \
    src/Countries.h \
    src/Question.h \
    src/Questions.h

RESOURCES += \
    ressource.qrc
