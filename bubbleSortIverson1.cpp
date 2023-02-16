#include "chw1.h"

void bubbleSortIverson1(std::vector<int> &array, size_t n) {
    int i = 0;
    bool t = true;
    while (t) {
        t = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                t = true;
            }
        }
        ++i;
    }
}