#include "chw1.h"

void shellShellSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 3; // 1 арифметика, 1 присваивание, 1 сравнение
    for (int s = n / 2; s > 0; s /= 2) {
        ++operations; // 1 присваивание
        for (int i = s; i < n; ++i) {
            operations += 8; // 2 арифметики, 1 присваивание, 3 сравнения, 2 обращения
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                std::swap(array[j], array[j + s]);
                operations += 12; // 8 из цикла, 1 арифметика, 2 обращения, 1 вызов функции
            }
            operations += 2; // 2 из цикла
        }
        operations += 2; // 2 из цикла
    }
}

void shellShellSort(std::vector<int> &array, size_t n) {
    for (int s = n / 2; s > 0; s /= 2) {
        for (int i = s; i < n; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                std::swap(array[j], array[j + s]);
            }
        }
    }
}