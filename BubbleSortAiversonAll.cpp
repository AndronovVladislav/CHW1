#include "chw1.h"

void bubbleSortAiversonAllOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 6; // 4 присваивания, 2 арифметики
    bool t = true;
    int i = 0, l = n + 1, l1 = n - 1;
    while (t) {
        t = false;
        l = l < l1 ? l : l1;
        operations += 5; // 2 сравнение, 3 присваивания
        for (int j = 0; j < l; ++j) {
            operations += 4; // 1 арифметика, 2 обращения, 1 сравнение
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                t = true;
                l1 = j;
                operations += 6; // 2 присваивания, 2 обращения, 1 арифметика, 1 вызов функции
            }
            operations += 2; // из цикла
        }
        ++i;
        operations += 2; // 1 присваивание + 1 из цикла
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