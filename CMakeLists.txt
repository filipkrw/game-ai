cmake_minimum_required(VERSION 3.26)

project(GameAI)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.6.0 COMPONENTS window graphics system REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics sfml-system)
