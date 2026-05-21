cmake_minimum_required(VERSION 4.2)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled src/main.cpp
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/settings/settings.cpp
        src/settings/settings.h)
