cmake_minimum_required(VERSION 3.16)
project(Helix2D C CXX)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    message(STATUS "Building on Windows platform.")
elseif (APPLE)
    message(STATUS "Building on MacOS platform.")
    add_compile_definitions(TARGET_OS_MAC)
elseif (UNIX)
    message(STATUS "Building on UNIX-like OS platform.")
endif ()

include_directories(include/helix2d)

add_subdirectory(source)
add_subdirectory(source/Base)
add_subdirectory(source/Inbuilt)
add_subdirectory(source/Module)
add_subdirectory(source/Tool)

add_subdirectory(source/Render)
add_subdirectory(source/Render/Camera)
add_subdirectory(source/Render/Image)
add_subdirectory(source/Render/Shape)
add_subdirectory(source/Render/Text)






