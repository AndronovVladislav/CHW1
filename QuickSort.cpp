#include "chw1.h"

int quickSortPartitionOperations(std::vector<int> &array, int l, int r, int64_t &operations) {
    operations += 3;
    int pivot = array[l];
    int i = l;
    int j = r;
    while (i <= j) {
        while (array[i] < pivot) {
            ++i; ++operations;
        }

        while (array[j] > pivot) {
            --j; ++operations;
        }

        ++operations;
        if (i >= j) {
            break;
        }

        std::swap(array[i++], array[j--]);
        operations += 3;
    }
    return j;
}

void quickSortOperations(std::vector<int> &array, int l, int r, int64_t &operations) {
    ++operations;
    if (l < r) {
        int q = quickSortPartitionOperations(array, l, r, operations);
        quickSortOperations(array, l, q, operations);
        quickSortOperations(array, q + 1, r, operations);
        operations += 3;
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