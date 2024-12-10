cmake_minimum_required(VERSION 3.29)
project(MCJE_CXX)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML
        COMPONENTS
            system
            network
            window
            graphics
            audio
        CONFIG
            REQUIRED)
find_package(glad CONFIG REQUIRED)

add_executable(MCJE_CXX)

target_link_libraries(MCJE_CXX
        PRIVATE
            sfml-system
            sfml-network
            sfml-graphics
            sfml-window
            sfml-audio
            glad::glad)

set(SRC_DIR src)

file(GLOB_RECURSE SRC_DIR_LIST "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.c")
message(STATUS "SRC_DIR_LIST = ${SRC_DIR_LIST}")
target_sources(MCJE_CXX PRIVATE ${SRC_DIR_LIST})

target_include_directories(MCJE_CXX PRIVATE src)