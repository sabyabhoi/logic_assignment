cmake_minimum_required(VERSION 3.1)

set(BINARY ${CMAKE_PROJECT_NAME}_run)

#project(logic_1 LANGUAGES CXX)

#include_directories(../include)

add_library(utils utils.cpp)
add_library(parse_tree parse_tree.cpp)
add_library(linked_list linked_list.cpp)
add_library(stack stack.cpp)

add_executable(${BINARY} main.cpp)
target_link_libraries(${BINARY} utils parse_tree linked_list stack)
