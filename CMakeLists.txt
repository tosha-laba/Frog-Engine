cmake_minimum_required(VERSION 3.15)
project(frog_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES src/main.cpp)


add_executable(frog_engine ${SOURCES})

add_subdirectory(src)

target_link_libraries(frog_engine src)