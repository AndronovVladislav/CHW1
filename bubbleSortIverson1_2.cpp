#include "chw1.h"

void bubbleSortIverson1_2(std::vector<int> &array, size_t n) {
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