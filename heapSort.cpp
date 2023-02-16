#include "chw1.h"

void siftDown(std::vector<int> &array, int i, size_t heapSize) {
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;

        if (right < heapSize && array[left] < array[right]) {
            j = right;
        }

        if (array[j] < array[i] || !((array[i] < array[j]) || (array[j] < array[i]))) {
            break;
        }

        std::swap(array[i], array[j]);
        i = j;
    }
}

void buildHeap(std::vector<int> &array) {
    for (int i = static_cast<int>(array.size() / 2); i > -1; --i) {
        siftDown(array, i, array.size());
    }
}

void heapSort(std::vector<int> &array, size_t n) {
    buildHeap(array);
    size_t heapSize = n;
    for (int i = 0; i < n; ++i) {
        std::swap(array[0], array[n - 1 - i]);
        --heapSize;
        siftDown(array, 0, heapSize);
    }
}