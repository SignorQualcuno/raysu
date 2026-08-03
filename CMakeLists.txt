cmake_minimum_required(VERSION 4.3.0)
project(Raysu LANGUAGES CXX)

# Output all binaries to the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 1. Tell CMake to include the built-in FetchContent module
include(FetchContent)

# 2. Tell CMake where to download RayLib from (we are using version 6.0)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        6.0
)
FetchContent_MakeAvailable(raylib)

# 3. Find your source files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

# 4. Create your executable
add_executable(Raysu ${SRC_FILES})
target_include_directories(Raysu PRIVATE src)

# 5. THE FIX: Link RayLib to your Game
target_link_libraries(Raysu PRIVATE raylib)
