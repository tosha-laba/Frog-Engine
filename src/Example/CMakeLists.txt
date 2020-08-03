project(Example)

set(
        SOURCES

        GameScene.cpp
        LogoScene.cpp
        MenuScene.cpp
        PlatformerEngine.cpp
        Player.cpp
        Spritemap.cpp
        Tilemap.cpp
)

set(
        HEADERS

        GameScene.h
        LogoScene.h
        MenuScene.h
        PlatformerEngine.h
        Player.h
        Spritemap.h
        Tilemap.h
)

include_directories(../)

add_library(Example ${SOURCES} ${HEADERS})