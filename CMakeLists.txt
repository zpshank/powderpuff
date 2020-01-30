if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "This library does not support same directory builds. Change to a different build directory.")
endif()

cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

project(powderpuff CXX C)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(SRC "${CMAKE_SOURCE_DIR}/src")
set(INC "${CMAKE_SOURCE_DIR}/include")

set(powderpuff_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/${INC}")

add_library(powderpuff STATIC)
target_sources(powderpuff
    PUBLIC 
        ${INC}/Game.h
        ${INC}/AssetStore.h
        ${INC}/Sprite.h
        ${SRC}/Game.cpp
        ${SRC}/AssetStore.cpp
        ${SRC}/Sprite.cpp
)
target_include_directories(powderpuff
    PUBLIC 
        ${INC}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
)
target_link_libraries(powderpuff
    PUBLIC 
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
)

add_subdirectory(example)
