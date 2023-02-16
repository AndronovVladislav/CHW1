#include "chw1.h"

void shellShellSort(std::vector<int> &array, size_t n) {
    for (int s = static_cast<int>(n) / 2; s > 0; s /= 2) {
        for (int i = s; i < n; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}