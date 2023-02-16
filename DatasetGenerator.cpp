#include "chw1.h"

std::vector<int> DatasetGenerator::generateRandomArray(int min, int max) {
    std::mt19937 generator(time(nullptr));
    std::uniform_int_distribution<> randint(min, max);
    std::vector<int> result(4100);

    for (size_t i = 0; i < 4100; ++i) {
        result[i] = randint(generator);
    }

    return result;
}

std::vector<int> DatasetGenerator::almostSortedArray(int min, int max) {
    std::mt19937 generator(time(nullptr));
    std::uniform_int_distribution<> randint(min, max);
    std::vector<int> result(4100);

    for (int i = 0; i < 4000; ++i) {
        result[i] = i;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 1000 * 0.015; ++j) {
            int l = (randint(generator) % 1000) + 1000 * i, r = (randint(generator) % 1000) + 1000 * i;
            std::swap(result[l], result[r]);
        }
    }

    return result;
}

std::vector<int> DatasetGenerator::reversedSortedArray(int min, int max) {
    std::vector<int> result(4100);
    for (int i = max; i > min; --i) {
        result[4100 - i] = i;
    }
    return result;
}