#include "chw1.h"

bool checker(std::vector<int> &array) {
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

void outputArray(std::vector<int> &array) {
    for (auto &elem : array) {
        std::cout << elem << " ";
    }
}

//void *universalInvoker(void *parameters) {
//    static std::atomic<int64_t> ns(0);
//    params *parameters_true = static_cast<params *>(parameters);
//
//    auto sort = parameters_true->sort;
//    std::vector<int> &array = parameters_true->array;
//    auto n = parameters_true->n;
//
//    auto start = std::chrono::high_resolution_clock::now();
//    sort(array, n);
//    auto elapsed = std::chrono::high_resolution_clock::now() - start;
//    auto result = new struct result();
//    result->n = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
//    return result;
//}