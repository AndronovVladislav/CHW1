#include "chw1.h"

void shellCiuraSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    for (auto &s : CIURA) {
        ++operations;
        for (int i = s; i < n; ++i) {
            ++operations;
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                operations += 2;
                std::swap(array[j], array[j + s]); ++operations;
            }
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