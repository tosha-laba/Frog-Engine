project(AppComponents)

set(
        SOURCES

        AudioComponent.cpp
        GraphicsComponent.cpp
        WindowComponent.cpp
)

set(
        HEADERS

        AudioComponent.h
        GraphicsComponent.h
        WindowComponent.h
)

include_directories(../)

add_library(AppComponents ${SOURCES} ${HEADERS})