#include "chw1.h"

int partition(std::vector<int> &array, int l, int r) {
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
        int q = partition(array, l, r);
        quickSort(array, l, q);
        quickSort(array, q + 1, r);
    }
}

void quickSort(std::vector<int> &array, size_t n) {
    quickSort(array, 0, n);
}