#include "chw1.h"

void heapSortSiftDownOperations(std::vector<int> &array, int i, size_t heapSize, int64_t &operations) {
    operations += 3; // 2 арифметики, 1 сравнение
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        operations += 7; // 4 арифметики, 3 присваивания

        operations += 5; // 3 сравнения, 2 обращения
        if (right < heapSize && array[left] < array[right]) {
            j = right;
            ++operations;
        }

        operations += 3;
        if (array[j] <= array[i]) {
            ++operations;
            break;
        }

        std::swap(array[i], array[j]);
        i = j;
        operations += 4;
    }
}

void heapSortBuildHeapOperations(std::vector<int> &array, int64_t &operations) {
    ++operations; // 1 арифметика
    for (int i = array.size() / 2; i > -1; --i) {
        heapSortSiftDownOperations(array, i, array.size(), operations);
        operations += 4; // 2 из цикла, 2 вызова функций
    }
}

void heapSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 2;

    heapSortBuildHeapOperations(array, operations);
    size_t heapSize = n;

    for (int i = 0; i < n; ++i) {
        std::swap(array[0], array[n - i - 1]);
        --heapSize;
        heapSortSiftDownOperations(array, 0, heapSize, operations);
        operations += 8; // 2 обращения, 2 арифметики, 1 присваивание, 1 вызов функции,
                         // 2 из цикла
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