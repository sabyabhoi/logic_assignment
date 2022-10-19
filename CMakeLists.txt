cmake_minimum_required(VERSION 3.24.2)
project(proParser)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") 

include_directories(include)

link_directories(include)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
