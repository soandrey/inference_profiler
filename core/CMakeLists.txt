cmake_minimum_required(VERSION 3.16)
project(core)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(inference)

if(${ANDROID})
    add_subdirectory(android)
else()
    add_executable(core main.cpp)
    target_link_libraries(core PRIVATE inference)
endif()

