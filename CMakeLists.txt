cmake_minimum_required(VERSION 4.2)
project(Vengine)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)

add_executable(untitled src/main.cpp
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/settings/Settings.cpp
        src/settings/Settings.h)

target_link_libraries(untitled
        glfw)