cmake_minimum_required(VERSION 3.16)
project(CHW1)

set(CMAKE_CXX_STANDARD 11)

add_executable(CHW1 tester.cpp BubbleSort.cpp BubbleSortAiverson1.cpp BubbleSortAiversonAll.cpp
        HeapSort.cpp HeapSort.cpp MergeSort.cpp QuickSort.cpp RadixSort.cpp
        SelectionSort.cpp ShellCiuraSort.cpp ShellShellSort.cpp StableCountingSort.cpp InsertionSort.cpp
        BinaryInsertionSort.cpp Utils.cpp)
