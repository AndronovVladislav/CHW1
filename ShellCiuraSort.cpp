#include "chw1.h"

void shellCiuraSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    for (auto &s : CIURA) {
        operations += 2; // 2 присвоение(s и i)
        for (int i = s; i < n; ++i) {
            operations += 8; // 2 арифметики, 1 присваивание, 3 сравнения, 2 обращения
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                std::swap(array[j], array[j + s]);
                operations += 12; // 8 из цикла, 1 арифметика, 2 обращения, 1 вызов функции
            }
            operations += 2; // из цикла
        }
    }
}

void shellCiuraSort(std::vector<int> &array, size_t n) {
    for (auto &s : CIURA) {
        for (int i = s; i < n; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                std::swap(array[j], array[j + s]);
            }
        }
    }
}