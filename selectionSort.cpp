#include "chw1.h"

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