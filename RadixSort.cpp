#include "chw1.h"

int digit(int number, int index) {
    return (number & (0xFF << (index << 3))) >> (index << 3);
}

void radixSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 2 + 256 + n;
    int k = 256, m = 4;
    std::vector<int> c(256, 0);
    std::vector<int> b(n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            c[j] = 0; ++operations;
        }

        for (int j = 0; j < n; ++j) {
            int d = digit(array[j], i); operations += 6;
            ++c[d]; ++operations;
        }

        int count = 0; ++operations;
        for (int j = 0; j < k; ++j) {
            int tmp = c[j];
            c[j] = count;
            count += tmp; operations += 3;
        }

        for (int j = 0; j < n; ++j) {
            int d = digit(array[j], i); operations += 6;
            b[c[d]] = array[j];
            ++c[d]; operations += 2;
        }

        array = b; ++operations;
    }
}

void radixSort(std::vector<int> &array, size_t n) {
    int k = 256, m = 4;
    std::vector<int> c(256, 0);
    std::vector<int> b(n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            c[j] = 0;
        }

        for (int j = 0; j < n; ++j) {
            int d = digit(array[j], i);
            ++c[d];
        }

        int count = 0;
        for (int j = 0; j < k; ++j) {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }

        for (int j = 0; j < n; ++j) {
            int d = digit(array[j], i);
            b[c[d]] = array[j];
            ++c[d];
        }

        array = b;
    }
}