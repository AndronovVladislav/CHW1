#include "chw1.h"

void shellCiuraSort(std::vector<int> &array, size_t n) {
    for (auto s : CIURA) {
        for (int i = s; i < n; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}