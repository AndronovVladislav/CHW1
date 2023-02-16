#include "chw1.h"

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