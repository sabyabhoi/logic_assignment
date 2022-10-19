cmake_minimum_required(VERSION 3.1)

set(BINARY ${CMAKE_PROJECT_NAME}_run)

add_library(utils SHARED utils.cpp)
add_library(parse_tree SHARED parse_tree.cpp)
add_library(linked_list SHARED linked_list.cpp)
add_library(stack SHARED stack.cpp)
add_library(timer SHARED timer.cpp)

add_executable(${BINARY} main.cpp)
target_link_libraries(${BINARY} utils parse_tree linked_list stack)
