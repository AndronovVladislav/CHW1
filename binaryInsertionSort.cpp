#include "chw1.h"

int binSearch(std::vector<int>& array, int x, int l, int r) {
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
    int j, k;
    for (size_t i = 1; i < n; ++i) {
        j = i - 1;
        k = binSearch(array, array[i], -1, j + 1);
        for (int l = j; l > k - 1; --l) {
            std::swap(array[l], array[l + 1]);
        }
    }
}