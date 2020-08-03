project(Graphics)

set(
        HEADERS

        Image.h
)

include_directories(../)

add_library(Graphics ${HEADERS})