cmake_minimum_required(VERSION 3.16)
project(deadlock-optimizer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(deadlockoptimizer
    src/main.cpp
    src/tuner.cpp
    src/configs.cpp
    src/monitor.cpp
)

target_include_directories(deadlockoptimizer PRIVATE include)

if(WIN32)
    target_link_libraries(deadlockoptimizer PRIVATE userenv)
endif()
