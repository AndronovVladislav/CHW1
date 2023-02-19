#include "chw1.h"

void heapSortSiftDownOperations(std::vector<int> &array, int i, size_t heapSize, int64_t &operations) {
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left; operations += 3;

        operations += 2;
        if (right < heapSize && array[left] < array[right]) {
            j = right; ++operations;
        }

        ++operations;
        if (array[j] <= array[i]) {
            ++operations; break;
        }

        std::swap(array[i], array[j]);
        i = j; operations += 2;
    }
}

void heapSortBuildHeapOperations(std::vector<int> &array, int64_t &operations) {
    for (int i = array.size() / 2; i > -1; --i) {
        heapSortSiftDownOperations(array, i, array.size(), operations);
    }
}

void heapSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;

    heapSortBuildHeapOperations(array, operations);
    size_t heapSize = n; operations += 2;

    for (int i = 0; i < n; ++i) {
        std::swap(array[0], array[n - i - 1]);
        --heapSize;
        heapSortSiftDownOperations(array, 0, heapSize, operations); operations += 3;
    }
}

void heapSortSiftDown(std::vector<int> &array, int i, size_t heapSize) {
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;

        if (right < heapSize && array[left] < array[right]) {
            j = right;
        }

        if (array[j] <= array[i]) {
            break;
        }

        std::swap(array[i], array[j]);
        i = j;
    }
}

void heapSortBuildHeap(std::vector<int> &array) {
    for (int i = array.size() / 2; i > -1; --i) {
        heapSortSiftDown(array, i, array.size());
    }
}

void heapSort(std::vector<int> &array, size_t n) {
    heapSortBuildHeap(array);
    size_t heapSize = n;
    for (int i = 0; i < n; ++i) {
        std::swap(array[0], array[n - 1 - i]);
        --heapSize;
        heapSortSiftDown(array, 0, heapSize);
    }
}