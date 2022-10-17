cmake_minimum_required(VERSION 3.24.2)
project(proParser)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
