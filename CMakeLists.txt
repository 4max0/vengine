cmake_minimum_required(VERSION 4.2)
project(Vengine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Doxygen REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(untitled
        src/main.cpp
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/settings/Settings.cpp
        src/settings/Settings.h
        src/settings/Debug.cpp
        src/settings/Debug.h
)

target_link_libraries(untitled
        PRIVATE
        glfw
        Vulkan::Vulkan
)

add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating Doxygen documentation"
        VERBATIM
)