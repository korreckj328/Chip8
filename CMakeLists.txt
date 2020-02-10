cmake_minimum_required(VERSION 3.13)
project(Chip8)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)

add_executable(Chip8 main.cpp Display.cpp Display.h Chip8.cpp Chip8.h stack-jdk/stackADT.h stack-jdk/stackArray.h)


target_link_libraries(Chip8 ${SDL2_LIBRARIES})
