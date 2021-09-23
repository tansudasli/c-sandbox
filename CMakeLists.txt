cmake_minimum_required(VERSION 3.17)
project(c)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

#run w/
# cmake --build cmake-build-debug --target all -- -j 9
add_executable(arrays
        src/arrays.c)

add_executable(arraysIntvsChar
        src/arraysIntvsChar.c)

add_executable(fileHandling
        src/header/search.h
        src/fileHandling.c
        src/utility/search.c)

FILE(COPY src/resources/dummy.txt
        DESTINATION "${CMAKE_BINARY_DIR}/resources")

#set(RESOURCE_FILES
#        src/resources/dummy.txt)
#
#set_target_properties(fileHandling PROPERTIES
#        MACOSX_BUNDLE TRUE
#        MACOSX_FRAMEWORK_IDENTIFIER org.cmake.ExecutableTarget
#        RESOURCE "${RESOURCE_FILES}")

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
        src/pointerAndCharArrays.c)

add_executable(pointerOperators
        src/pointerOperators.c)

add_executable(pointerInFunctions
        src/pointerInFunctions.c)

add_executable(structsAsArrays
        src/structsAsArrays.c)

add_executable(userInput
        src/userInput.c)

add_executable(variables
        src/variables.c)

#advanced C
add_executable(pointer
        src/pointer.c)

add_executable(pointerIndirection
        src/pointerIndirection.c)

add_executable(pointerToStringArray
        src/pointerToStringArray.c)


add_executable(pointerToFunctions
        src/pointerToFunctions.c)

add_executable(pointerToIntegerArray
        src/pointerToIntegerArray.c)

add_executable(pointerToFunctionReturns
        src/pointerToFunctionReturns.c)

add_executable(pointerToStruct
        src/pointerToStruct.c)

add_executable(structBasics
        src/structBasics.c)

add_executable(structsHasPointers
        src/structsHasPointers.c)

add_executable(memory
        src/memory2.c)

add_executable(memory2
        src/memory.c)

#dynamic
add_executable(fibonacci src/dynamic-programming/fibonacci.c)
add_executable(gridTraveller src/dynamic-programming/gridTraveller.c)

#concurrency
add_executable(semaphore
        src/concurrency/semaphore.c)

add_executable(forking
        src/concurrency/forking.c)

add_executable(forkingExec
        src/concurrency/forkingExec.c)

add_executable(threading
        src/concurrency/threading.c)