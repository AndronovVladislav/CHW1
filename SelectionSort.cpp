#include "chw1.h"

void selectionSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min = i;
        ++operations;
        for (size_t j = i + 1; j < n; ++j) {
            ++operations;
            if (array[j] < array[min]) {
                min = j;
                ++operations;
            }
        }

        std::swap(array[i], array[min]);
        ++operations;
    }
}

void selectionSort(std::vector<int> &array, size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }

        std::swap(array[i], array[min]);
    }
}