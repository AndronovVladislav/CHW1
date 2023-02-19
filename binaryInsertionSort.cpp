#include "chw1.h"

int binSearchOperations(std::vector<int> &array, int x, int l, int r,
                                           int64_t &operations) {
    while (l < r - 1) {
        int mid = (l + r) / 2;
        operations += 3;
        if (array[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

void binaryInsertionSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 2;
    int j;
    int k;
    for (size_t i = 1; i < n; ++i) {
        j = i - 1;
        k = binSearchOperations(array, array[i], -1, j + 1, operations); operations += 2;
        for (int l = j; l > k - 1; --l) {
            std::swap(array[l], array[l + 1]); ++operations;
        }
    }
}

int binSearch(std::vector<int> &array, int x, int l, int r) {
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (array[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

void binaryInsertionSort(std::vector<int> &array, size_t n) {
    int j;
    int k;
    for (size_t i = 1; i < n; ++i) {
        j = i - 1;
        k = binSearch(array, array[i], -1, j + 1);
        for (int l = j; l > k - 1; --l) {
            std::swap(array[l], array[l + 1]);
        }
    }
}