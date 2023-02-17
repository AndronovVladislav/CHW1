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

void bubbleSort(std::vector<int> &array, size_t n);
void bubbleSortIverson1(std::vector<int> &array, size_t n);
void bubbleSortIverson1_2(std::vector<int> &array, size_t n);

void insertionSort(std::vector<int> &array, size_t n);
void binaryInsertionSort(std::vector<int> &array, size_t n);

void stableCountingSort(std::vector<int> &array, size_t n);

int digit(int number, int index);
void radixSort(std::vector<int> &array, size_t n);

void merge(std::vector<int>::iterator &left, std::vector<int>::iterator &middle,
           std::vector<int>::iterator &right);
void mergeSort(std::vector<int> &array, size_t l, size_t r);
void mergeSort(std::vector<int> &array, size_t n);

int partition(std::vector<int> &array, int l, int r);
void quickSort(std::vector<int> &array, int l, int r);
void quickSort(std::vector<int> &array, size_t n);

void siftDown(std::vector<int> &array, int i, int heapSize);
void buildHeap(std::vector<int> &array);
void heapSort(std::vector<int> &array, size_t n);

void shellShellSort(std::vector<int> &array, size_t n);
void shellCiuraSort(std::vector<int> &array, size_t n);

void outputArray(std::vector<int> &array);

class Utils {
public:
    static std::vector<int> generateRandomArray(int min, int max);
    static std::vector<int> almostSortedArray(int min, int max);
    static std::vector<int> reversedSortedArray(int min, int max);
    static bool checker(std::vector<int> &array);
};

#endif //CHW1_CHW1_H
