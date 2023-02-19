#include "chw1.h"

void stableCountingSortOperations(std::vector<int> &array, size_t n, int64_t &operations) {
    operations = 4102 + n;
    std::vector<int> occurrences(4102, 0);
    std::vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        ++occurrences[array[i]];
    }
    operations += n;

    for (int i = 1; i < 4102; ++i) {
        occurrences[i] += occurrences[i - 1];
    }
    operations += 4102;

    for (int i = n - 1; i > -1; --i) {
        --occurrences[array[i]];
        result[occurrences[array[i]]] = array[i]; operations += 2;
    }

    array = result; ++operations;
}

void stableCountingSort(std::vector<int> &array, size_t n) {
    std::vector<int> occurrences(4102, 0);
    std::vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        ++occurrences[array[i]];
    }

    for (int i = 1; i < 4102; ++i) {
        occurrences[i] += occurrences[i - 1];
    }

    for (int i = n - 1; i > -1; --i) {
        --occurrences[array[i]];
        result[occurrences[array[i]]] = array[i];
    }

    array = result;
}