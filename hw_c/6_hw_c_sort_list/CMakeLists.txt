cmake_minimum_required(VERSION 3.10)
project(sortingListProject C)

include_directories(. test)

add_executable(testApp test/testSortList.c list.c)

enable_testing()
add_test(NAME runTests COMMAND testApp)
add_executable(program sortList.c list.c)