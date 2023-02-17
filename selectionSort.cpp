#include "chw1.h"

void selectionSort(std::vector<int> &array, size_t n) {
    int64_t operations = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min = i; ++operations;
        for (size_t j = i + 1; j < n; ++j) {
            ++operations;
            if (array[j] < array[min]) {
                min = j;
                ++operations;
            }
        }

        array[i] ^= array[min];
        array[min] ^= array[i];
        array[i] ^= array[min];
        operations += 3;
    }
}