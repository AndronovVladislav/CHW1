#include "chw1.h"

void merge(std::vector<int> &array, int left, int middle, int right) {
    int it1 = 0, it2 = 0, size = right - left;
    int result[size];

    while (left + it1 != middle && middle + it2 != right) {
        if (array[left + it1] < array[middle + it2]) {
            result[it1 + it2] = array[left + it1];
            ++it1;
        } else {
            result[it1 + it2] = array[middle + it2];
            ++it2;
        }
    }

    while (left + it1 != middle) {
        result[it1 + it2] = array[left + it1];
        ++it1;
    }

    while (middle + it2 != right) {
        result[it1 + it2] = array[middle + it2];
        ++it2;
    }

    for (int i = 0; i < it1 + it2; ++i) {
        array[left + i] = result[i];
    }
}

void mergeSort(std::vector<int> &array, size_t l, size_t r) {
    if (l == r || l + 1 == r) {
        return;
    }

    mergeSort(array, l, (l + r) / 2);
    mergeSort(array, (l + r) / 2, r);
    merge(array, l, (l + r) / 2, r);
}

void mergeSort(std::vector<int> &array, size_t n) {
    mergeSort(array, 0, n);
}