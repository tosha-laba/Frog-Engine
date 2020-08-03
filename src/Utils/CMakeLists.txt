project(Utils)

set(
        HEADERS

        BoundingBox.h
        Color.h
        INativeImage.h
        INativeSound.h
)

include_directories(../)

add_library(Utils ${HEADERS})