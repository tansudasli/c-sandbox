cmake_minimum_required(VERSION 3.17)
project(c_sandbox)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

#run w/
# cmake --build cmake-build-debug --target all -- -j 9
add_executable(arrays
        src/arrays.c)

add_executable(fileHandling
        src/fileHandling.c)

add_executable(getInput
        src/header/interaction.h
        src/getInput.c
        src/utility/interaction.c)

add_executable(helloworld
        src/helloworld.c)

add_executable(manipulationsChar
        src/manipulationsChar.c)

add_executable(manipulationsString
        src/manipulationsString.c)

add_executable(operators
        src/operators.c)

add_executable(operatorsLogical
        src/operatorsLogical.c)

add_executable(operatorsSwitch
        src/operatorsSwitch.c)

add_executable(pointersAndCharArrays
        src/pointersAndCharArrays.c)

add_executable(pointersArithmetic
        src/pointersArithmetic.c)

add_executable(pointersStringFunctions
        src/pointersStringFunctions.c)

add_executable(structs
        src/structs.c
        src/utility/initialize.c)

add_executable(userInput
        src/userInput.c)

add_executable(variables
        src/variables.c)