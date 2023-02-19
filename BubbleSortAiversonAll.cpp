#include "chw1.h"

void bubbleSortAiversonAllOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 4;
    bool t = true;
    int i = 0, l = n + 1, l1 = n - 1;
    while (t) {
        t = false;
        l = l < l1 ? l : l1; operations += 3;
        for (int j = 0; j < l; ++j) {
            ++operations;
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                t = true;
                l1 = j; operations += 3;
            }
        }
        ++i; ++operations;
    }
}

void bubbleSortAiversonAll(std::vector<int> &array, size_t n) {
    bool t = true;
    int i = 0, l = n + 1, l1 = n - 1;
    while (t) {
        t = false;
        l = l < l1 ? l : l1;
        for (int j = 0; j < l; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                t = true;
                l1 = j;
            }
        }
        ++i;
    }
}