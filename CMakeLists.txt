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

add_executable(MCJE_CXX source/main.cpp)

target_link_libraries(MCJE_CXX
        PRIVATE
            sfml-system
            sfml-network
            sfml-graphics
            sfml-window
            sfml-audio
            glad::glad)