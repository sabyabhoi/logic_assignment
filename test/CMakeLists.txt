set(BINARY ${CMAKE_PROJECT_NAME}_test)

add_executable(${BINARY} test.cpp)
target_link_libraries(${BINARY} PUBLIC gtest)
