cmake_minimum_required(VERSION 3.31)
project(SkyWorld)

set(CMAKE_CXX_STANDARD 20)

add_executable(SkyWorld main.cpp
        arrays.cpp)
add_executable(functions Functions/functions.cpp)
add_executable(game Functions/game.cpp)
add_executable(functionPointers Functions/function_pointers.cpp)
add_executable(bubble_sort Pointers/bubble_sort.cpp)
add_executable(func_pointers_array Functions/function_pointers_array.cpp)