#include "chw1.h"

void bubbleSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    for (int i = 0; i < n - 1; ++i) {
        operations += 2; // 2 из цикла
        for (int j = 0; j < n - i - 1; ++j) {
            operations += 9; // 3 из цикла, 1 сравнение, 2 обращение, 3 арифметики
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                operations += 4;
            }
        }
    }
}

void bubbleSort(std::vector<int> &array, size_t n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}