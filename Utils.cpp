#include "chw1.h"

std::vector<int> Utils::generateRandomArray(int min, int max) {
    std::mt19937 generator(time(nullptr));
    std::uniform_int_distribution<> randint(min, max);
    std::vector<int> result(4100);

    for (size_t i = 0; i < 4100; ++i) {
        result[i] = randint(generator);
    }

    return result;
}

std::vector<int> Utils::almostSortedArray(int min, int max) {
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

std::vector<int> Utils::reversedSortedArray(int min, int max) {
    std::vector<int> result(4100);
    for (int i = max; i > min; --i) {
        result[4100 - i] = i;
    }
    return result;
}

bool Utils::checker(std::vector<int> &array) {
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

std::string Utils::getArrayTypename(size_t &array_type) {
    switch (array_type) {
        case 0:
            return "Random(0-5)";
        case 1:
            return "Random(0-4000)";
        case 2:
            return "AlmostSorted";
        case 3:
            return "ReversedSorted";
        default:
            return "";
    }
}

void Utils::outputArray(std::vector<int> &array) {
    for (auto &elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}