cmake_minimum_required(VERSION 3.31)
project(SkyWorld)

set(CMAKE_CXX_STANDARD 20)

add_executable(SkyWorld main.cpp)
add_executable(functions Functions/functions.cpp)
add_executable(game Functions/game.cpp)
add_executable(functionPointers Functions/function_pointers.cpp)
add_executable(bubble_sort Pointers/bubble_sort.cpp)
add_executable(func_pointers_array Functions/function_pointers_array.cpp)
add_executable(arrays Arrays/multidimensional_arrays.cpp)
add_executable(classes Classes/Animal/Animal.cpp)
add_executable(classes_1 Classes/BankAccount/BankAccount.cpp)
add_executable(main_class
        Classes/main.cpp
        Classes/BankAccount/BankAccount.cpp
        Classes/Animal/Animal.cpp
)

add_executable(person Classes/Person.cpp)
add_executable(operator_overloading
        OperatorOverloading/Complex.cpp
)
add_executable(operator_overloading_1
        OperatorOverloading/Foo.cpp)
add_executable(operator_overloading_2
        OperatorOverloading/Foo2D.cpp)
add_executable(operator_overloading_3
        OperatorOverloading/Student.cpp
)

add_executable(Inheritance Inheritance/Inheritance.cpp)
add_executable(Function_templates Templates/Arithmetic.cpp)
add_executable(Class_templates Templates/Stack.cpp)
add_executable(class_templates_2 Templates/LinkedList.cpp)

