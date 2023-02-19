#ifndef CHW1_CHW1_H
#define CHW1_CHW1_H
#define TESTS_AMOUNT 100
#define SMALL_SIZES { 50, 100, 150, 200, 250, 300 }
#define LARGE_SIZES { 100, 200, 300, 400, 500, 600, 700, 800, 900,     \
                      1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700,  \
                      1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500,  \
                      2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300,  \
                      3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100   \
}
#define CIURA { 1, 4, 10, 23, 57, 132, 301, 701, 1750 }

#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <unordered_map>

void selectionSort(std::vector<int> &array, size_t n);
void selectionSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void bubbleSort(std::vector<int> &array, size_t n);
void bubbleSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void bubbleSortAiverson1(std::vector<int> &array, size_t n);
void bubbleSortAiverson1Operations(std::vector<int> &array, size_t n, int64_t &operations);

void bubbleSortAiversonAll(std::vector<int> &array, size_t n);
void bubbleSortAiversonAllOperations(std::vector<int> &array, size_t n, int64_t &operations);

void insertionSort(std::vector<int> &array, size_t n);
void insertionSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void binaryInsertionSort(std::vector<int> &array, size_t n);
void binaryInsertionSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void stableCountingSort(std::vector<int> &array, size_t n);
void stableCountingSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void radixSort(std::vector<int> &array, size_t n);
void radixSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void mergeSort(std::vector<int> &array, size_t n);
void mergeSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void quickSort(std::vector<int> &array, size_t n);
void quickSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void heapSort(std::vector<int> &array, size_t n);
void heapSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void shellShellSort(std::vector<int> &array, size_t n);
void shellShellSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

void shellCiuraSort(std::vector<int> &array, size_t n);
void shellCiuraSortOperations(std::vector<int> &array, size_t n, int64_t &operations);

class Utils {
public:
    static std::vector<int> generateRandomArray(int min, int max);
    static std::vector<int> almostSortedArray(int min, int max);
    static std::vector<int> reversedSortedArray(int min, int max);
    static bool checker(std::vector<int> &array);
    static std::string getArrayTypename(size_t &array_type);
    static void outputArray(std::vector<int> &array);
};

#endif //CHW1_CHW1_H
