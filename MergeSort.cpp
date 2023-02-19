#include "chw1.h"

void mergeOperations(std::vector<int> &array, int left, int middle, int right, int64_t& operations) {
    int it1 = 0, it2 = 0, size = right - left;
    operations += 3 + size;
    int result[size];

    operations += 5; // 2 сравнения, 1 логика, 2 арифметика
    while (left + it1 != middle && middle + it2 != right) {
        operations += 5; // 2 арифметика, 2 обращения, 1 сравнение
        if (array[left + it1] < array[middle + it2]) {
            result[it1 + it2] = array[left + it1];
            ++it1;
        } else {
            result[it1 + it2] = array[middle + it2];
            ++it2;
        }
        operations += 11; // внутри ифа: 2 арифметики, 2 присваивания, 2 обращения
                          // 5 операций на следующую итерацию
    }

    operations += 2;
    while (left + it1 != middle) {
        result[it1 + it2] = array[left + it1];
        ++it1;
        operations += 8; // 6 как в цикле выше, 2 на следующую итерацию
    }

    while (middle + it2 != right) {
        result[it1 + it2] = array[middle + it2];
        ++it2;
        operations += 8; // 6 как в цикле выше, 2 на следующую итерацию
    }

    for (int i = 0; i < it1 + it2; ++i) {
        array[left + i] = result[i];
        operations += 7; // 2 арифметики, 2 обращения, 1 присваивание, 2 из цикла
    }
}

void mergeSortOperations(std::vector<int> &array, size_t l, size_t r, int64_t& operations) {
    operations += 4; // 1 арифметика, 3 сравнения
    if (l == r || l + 1 == r) {
        return;
    }

    mergeSortOperations(array, l, (l + r) / 2, operations);
    mergeSortOperations(array, (l + r) / 2, r, operations);
    mergeOperations(array, l, (l + r) / 2, r, operations);
    operations += 3; // 3 из вызовов функций
}

void mergeSortOperations(std::vector<int> &array, size_t n, int64_t& operations) {
    operations = 0;
    mergeSortOperations(array, 0, n, operations);
}

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