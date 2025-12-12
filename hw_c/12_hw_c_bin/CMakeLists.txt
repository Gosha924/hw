cmake_minimum_required(VERSION 3.10)
project(binaryCalculator LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -Werror")
add_executable(bin bin.c)
