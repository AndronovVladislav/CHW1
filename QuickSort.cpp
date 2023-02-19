#include "chw1.h"

int quickSortPartitionOperations(std::vector<int> &array, int l, int r, int64_t &operations) {
    operations += 4; // 3 присваивания, 1 обращение
    int pivot = array[l];
    int i = l;
    int j = r;
    ++operations; // 1 сравнение
    while (i <= j) {
        operations += 2; // 1 сравнение, 1 обращение
        while (array[i] < pivot) {
            ++i;
            operations += 3; // присваивание + проверка на следующую итерацию
        }

        operations += 2; // 1 сравнение, 1 обращение
        while (array[j] > pivot) {
            --j;
            operations += 3; // присваивание + проверка на следующую итерацию
        }

        ++operations;
        if (i >= j) {
            ++operations;
            break;
        }

        std::swap(array[i++], array[j--]);
        operations += 6; // 2 присваивания, 2 обращения
                         // 1 вызов функции, 1 проверка на следующую итерацию
    }
    return j;
}

void quickSortOperations(std::vector<int> &array, int l, int r, int64_t &operations) {
    ++operations;
    if (l < r) {
        int q = quickSortPartitionOperations(array, l, r, operations);
        quickSortOperations(array, l, q, operations);
        quickSortOperations(array, q + 1, r, operations);
        operations += 5; // 1 присваивание, 3 вызова, 1 арифметика
    }
}

void quickSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 0;
    quickSortOperations(array, 0, n - 1, operations);
}

int quickSortPartition(std::vector<int> &array, int l, int r) {
    int pivot = array[l];
    int i = l;
    int j = r;
    while (i <= j) {
        while (array[i] < pivot) {
            ++i;
        }

        while (array[j] > pivot) {
            --j;
        }

        if (i >= j) {
            break;
        }

        std::swap(array[i++], array[j--]);
    }
    return j;
}

void quickSort(std::vector<int> &array, int l, int r) {
    if (l < r) {
        int q = quickSortPartition(array, l, r);
        quickSort(array, l, q);
        quickSort(array, q + 1, r);
    }
}

void quickSort(std::vector<int> &array, size_t n) {
    quickSort(array, 0, n - 1);
}