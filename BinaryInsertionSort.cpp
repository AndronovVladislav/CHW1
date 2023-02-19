#include "chw1.h"

int binSearchOperations(std::vector<int> &array, int x, int l, int r,
                                           int64_t &operations) {
    operations += 2;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        operations += 8; // 2 для следующей итерации, 2 присваивания, 1 сравнение,
                         // 2 арифметики, 1 обращение
        if (array[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

void binaryInsertionSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    int j;
    int k;
    for (size_t i = 1; i < n; ++i) {
        j = i - 1;
        k = binSearchOperations(array, array[i], -1, j + 1, operations);
        operations += 7; // 2 из цикла, 2 присваивание, 1 вызов функции, 1 обращение, 1 арифметика
        for (int l = j; l > k - 1; --l) {
            std::swap(array[l], array[l + 1]);
            operations += 6; // 2 из цикла, 1 вызов функции, 2 обращения, 1 арифметика
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