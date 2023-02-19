#include "chw1.h"

void insertionSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 1;
    int j;
    for (size_t i = 1; i < n; ++i) {
        j = i - 1; ++operations;
        while (j >= 0 && array[j] > array[j + 1]) {
            std::swap(array[j], array[j + 1]);
            --j;
            operations += 2;
        }
    }
}

void insertionSort(std::vector<int> &array, size_t n) {
    int j;
    for (size_t i = 1; i < n; ++i) {
        j = i - 1;
        while (j >= 0 && array[j] > array[j + 1]) {
            std::swap(array[j], array[j + 1]);
            --j;
        }
    }
}