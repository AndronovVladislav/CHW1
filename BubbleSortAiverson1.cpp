#include "chw1.h"

void bubbleSortAiverson1Operations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 2;
    int i = 0;
    bool t = true;
    while (t) {
        t = false;
        operations += 2; // 1 из цикла, 1 присваивание
        for (int j = 0; j < n - i - 1; ++j) {
            operations += 9; // 3 из цикла, 1 сравнение, 2 обращение, 3 арифметика
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                t = true;
                operations += 5;
            }
        }
        ++i;
        ++operations;
    }
}

void bubbleSortAiverson1(std::vector<int> &array, size_t n) {
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