cmake_minimum_required(VERSION 3.10)
project(doubleProject C)
set(CMAKE_C_STANDART 11)

enable_testing()
add_executable(testApp test.c double.c)
add_test(NAME runTests COMMAND testApp)

add_executable(main main.c double.c)
