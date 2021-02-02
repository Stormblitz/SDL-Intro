cmake_minimum_required(VERSION 3.5)
set(CMAKE_VERBOSE_MAKEFILE ON)

# set the project name
project(GameStarter)


set(CMAKE_BUILD_TYPE Debug)


include_directories(/usr/local/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)
find_package(SDL2TTF REQUIRED)

include_directories(SYSTEM ${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2TTF_INCLUDE_DIR})


add_executable(GameStarter 
    game/src/main.cpp 
)

add_custom_command(TARGET GameStarter PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:GameStarter>)
                       
# specify the C++ standard
target_compile_options(GameStarter
PRIVATE
    -std=c++14
    -pedantic
    -pedantic-errors
    -Wall
    -Wextra
    -Werror
    -Wno-float-equal
    -Wno-padded
    -Wno-unused-variable
    -Wno-unused-parameter
)

target_link_libraries(GameStarter ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2TTF_LIBRARY})

