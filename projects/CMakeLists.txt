cmake_minimum_required(VERSION 3.2...3.27.5)

project(kmms_practice)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)
add_subdirectory(bubble_sort_split)
add_subdirectory(refactoring_proj)
add_subdirectory(hello)
add_subdirectory(my_project)
add_subdirectory(unit_test)
add_subdirectory(scl)

set(CMAKE_SUPPRESS_REGENERATION true)