cmake_minimum_required(VERSION 3.20)
project(RaylibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Critical for Zed/clangd autocompletion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/scene_manager.cpp
)

# Link Fedora's system raylib
find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
