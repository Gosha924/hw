cmake_minimum_required(VERSION 3.10)
project(5_hw_c_sort_station LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Включение дополнительных предупреждений
add_compile_options(
    $<$<C_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic>
    $<$<C_COMPILER_ID:MSVC>:/W4>
)

add_library(stack 5_hw_c_stack/stack.c)
target_include_directories(stack PUBLIC 5_hw_c_stack)
add_executable(station station.c)
target_link_libraries(station stack)