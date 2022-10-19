set(BINARY ${CMAKE_PROJECT_NAME}_test)

add_executable(${BINARY} test.cpp parse_tree_test.cpp)
target_link_libraries(${BINARY} PUBLIC gtest stack linked_list parse_tree utils)
