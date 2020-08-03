project(AppTemplates)

set(
        SOURCES

        QtApp.cpp
        QtAudioComponent.cpp
        QtGraphicsComponent.cpp
        QtNativeImage.cpp
        QtNativeSound.cpp
        QtWindowComponent.cpp
)

set(
        HEADERS

        QtApp.h
        QtAudioComponent.h
        QtGraphicsComponent.h
        QtNativeImage.h
        QtNativeSound.h
        QtWindowComponent.h
)

include_directories(../)

add_library(AppTemplates ${SOURCES} ${HEADERS})