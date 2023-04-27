cmake_minimum_required(VERSION 3.0)

project(Lin_Alg)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -pipe -O2")

file(GLOB SOURCES "src/*.cpp")
add_executable(target ${SOURCES})

target_include_directories(target PUBLIC include/)
