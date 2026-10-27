cmake_minimum_required(VERSION 3.10)
project(cfps)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)

# Enable warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Add source directories
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add executable
add_executable(cfps src/main.c)