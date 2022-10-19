cmake_minimum_required (VERSION 3.8)
set(This LaTeX_linter)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# If you are working in Linux and want to check for memory leaks,
# uncomment this line:
# set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -fno-optimize-sibling-calls")
project (${This})
enable_testing()

find_package(nlohmann_json 3.2.0 REQUIRED)

add_subdirectory(googletest)

add_executable(application
    main.cpp Reader.cpp Reader.h
)

set(Headers
    Reader.h
)

set(Sources
    main.cpp
)
add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(linterTest)