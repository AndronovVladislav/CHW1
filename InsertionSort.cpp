#include "chw1.h"

void insertionSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    int j;
    for (size_t i = 1; i < n; ++i) {
        j = i - 1;
        operations += 9; // 2 из цикла, 1 присваивание, 3 сравнения, 2 обращения, 1 арифметика
        while (j >= 0 && array[j] > array[j + 1]) {
            std::swap(array[j], array[j + 1]);
            --j;
            operations += 10; // 2 из обращений, 1 присваивание, 1 вызов функции, 5
                              // сравнений для следующей итерации, 1 арифметика
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