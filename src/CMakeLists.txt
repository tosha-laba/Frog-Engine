project(src)

set(
        SOURCES

        App.cpp
        Engine.cpp
        Entity.cpp
        FG.cpp
        Graphic.cpp
        Scene.cpp
)

set(
        HEADERS

        App.h
        Engine.h
        Entity.h
        FG.h
        Graphic.h
        Scene.h
)

add_subdirectory(AppComponents)
add_subdirectory(AppTemplates)
add_subdirectory(Graphics)
add_subdirectory(Example)
add_subdirectory(Utils)

add_library(src ${SOURCES} ${HEADERS})