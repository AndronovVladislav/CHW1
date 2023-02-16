cmake_minimum_required(VERSION 3.16)
project(CHW1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=undefined,thread -fno-sanitize-recover=all -lpthread"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(CHW1 tester.cpp bubbleSort.cpp bubbleSortIverson1.cpp bubbleSortIverson1_2.cpp
        DatasetGenerator.cpp heapSort.cpp heapSort.cpp mergeSort.cpp quickSort.cpp radixSort.cpp
        selectionSort.cpp shellCiuraSort.cpp shellShellSort.cpp stableCountingSort.cpp insertionSort.cpp
        binaryInsertionSort.cpp utils.cpp)
