#include "chw1.h"

int digit(int number, int index) {
    return (number & (0xFF << (index * 8))) >> (index * 8);
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