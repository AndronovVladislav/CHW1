#include "chw1.h"

void shellShellSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    for (int s = n / 2; s > 0; s /= 2) {
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

void shellShellSort(std::vector<int> &array, size_t n) {
    for (int s = n / 2; s > 0; s /= 2) {
        for (int i = s; i < n; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                std::swap(array[j], array[j + s]);
            }
        }
    }
}