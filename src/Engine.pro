#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T19:42:10
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Engine
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
    Engine.cpp \
    Entity.cpp \
    Graphic.cpp \
    Scene.cpp \
    AppTemplates/QtApp.cpp \
    App.cpp \
    AppComponents/WindowComponent.cpp \
    AppComponents/AudioComponent.cpp \
    FG.cpp \
    AppComponents/GraphicsComponent.cpp \
    AppTemplates/QtWindowComponent.cpp \
    AppTemplates/QtAudioComponent.cpp \
    AppTemplates/QtGraphicsComponent.cpp \
    AppTemplates/QtNativeImage.cpp \
    AppTemplates/QtNativeSound.cpp \
    Example/PlatformerEngine.cpp \
    Example/LogoScene.cpp \
    Example/MenuScene.cpp \
    Example/GameScene.cpp \
    Example/Tilemap.cpp \
    Example/Spritemap.cpp \
    Example/Player.cpp

HEADERS += \
    Engine.h \
    Entity.h \
    Graphic.h \
    Scene.h \
    AppTemplates/QtApp.h \
    App.h \
    AppComponents/WindowComponent.h \
    AppComponents/AudioComponent.h \
    FG.h \
    AppComponents/GraphicsComponent.h \
    Utils/INativeImage.h \
    Utils/Color.h \
    Utils/BoundingBox.h \
    Graphics/Image.h \
    Utils/INativeSound.h \
    AppTemplates/QtWindowComponent.h \
    AppTemplates/QtAudioComponent.h \
    AppTemplates/QtGraphicsComponent.h \
    AppTemplates/QtNativeImage.h \
    AppTemplates/QtNativeSound.h \
    Example/PlatformerEngine.h \
    Example/LogoScene.h \
    Example/MenuScene.h \
    Example/GameScene.h \
    Example/Tilemap.h \
    Example/Spritemap.h \
    Example/Player.h
