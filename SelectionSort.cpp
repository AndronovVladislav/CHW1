#include "chw1.h"

void selectionSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min = i;
        operations += 3; // 2 из цикла, 1 присваивание
        for (size_t j = i + 1; j < n; ++j) {
            operations += 5; // 2 из цикла, 1 сравнение, 2 обращения
            if (array[j] < array[min]) {
                min = j;
                ++operations;
            }
        }

        std::swap(array[i], array[min]);
        operations += 3;
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