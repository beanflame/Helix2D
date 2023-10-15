cmake_minimum_required(VERSION 3.19)
project(demo C CXX)

include_directories(include)

file(GLOB APP_SOURCES source/*.cpp source/*.c)
add_executable(demo ${APP_SOURCES})

# 添加链接库文件(lib)
target_link_libraries(demo
        Helix2D
#        gcc
#        mingw32
        opengl32
        )