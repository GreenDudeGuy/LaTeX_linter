cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

set(This linterTests)

set (Sources
    linterTests.cpp
)

add_executable(linterTests linterTests.cpp)

target_link_libraries(${This} PUBLIC
    GTest::gtest_main
)


add_test(
    NAME linterTests
    COMMAND $<TARGET_FILE:linterTests>
)