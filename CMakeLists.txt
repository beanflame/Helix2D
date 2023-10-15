cmake_minimum_required(VERSION 3.19)
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

# add_subdirectory(source)

file(GLOB APP_SOURCES 
    source/*.cpp source/*.c
    source/Base/*.cpp source/Base/*.c
    source/Inbuilt/*.cpp source/Inbuilt/*.c
    source/Module/*.cpp source/Module/*.c
    source/Tool/*.cpp source/Tool/*.c

    source/Render/*.cpp source/Render/*.c
    source/Render/Camera/*.cpp source/Render/Camera/*.c
    source/Render/Image/*.cpp source/Render/Image/*.c
    source/Render/Shape/*.cpp source/Render/Shape/*.c
    source/Render/Text/*.cpp source/Render/Text/*.c
    )



add_library(Helix2D ${APP_SOURCES})


#target_link_libraries(space-longan-renderer
#        gcc
#        opengl32
#        )