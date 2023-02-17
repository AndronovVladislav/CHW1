#include "chw1.h"

class Tester {
public:
    Tester() {
        sorts = {selectionSort, bubbleSort, bubbleSortIverson1, bubbleSortIverson1_2,
                 insertionSort, binaryInsertionSort, stableCountingSort, radixSort,
                 mergeSort, quickSort, heapSort, shellShellSort, shellCiuraSort};

        origins = {Utils::generateRandomArray(0, 5), Utils::generateRandomArray(0, 4000),
                   Utils::almostSortedArray(0, 4000), Utils::reversedSortedArray(0, 4100)};

        sorts_accordance = {{selectionSort,        0},
                            {bubbleSort,           1},
                            {bubbleSortIverson1,   2},
                            {bubbleSortIverson1_2, 3},
                            {insertionSort,        4},
                            {binaryInsertionSort,  5},
                            {stableCountingSort,   6},
                            {radixSort,            7},
                            {mergeSort,            8},
                            {quickSort,            9},
                            {heapSort,             10},
                            {shellShellSort,       11},
                            {shellCiuraSort,       12},
        };
    }

    void startTests() {
        for (int i = 0; i < sorts.size(); ++i) {
            std::cout << "Completed: " << (i * 100) / sorts.size() << "%" << std::endl;
            for (auto size : SMALL_SIZES) {
                for (size_t j = 0; j < origins.size(); ++j) {
                    batchOfTests(sorts[i], origins[j], size, j);
                }
            }

            for (auto size : LARGE_SIZES) {
                for (size_t j = 0; j < origins.size(); ++j) {
                    batchOfTests(sorts[i], origins[j], size, j);
                }
            }
        }

        makeReport(records);
    }
private:
    std::vector<void (*)(std::vector<int> &, size_t)> sorts;
    std::vector<std::vector<int>> origins;
    std::unordered_map<void (*)(std::vector<int>&, size_t), size_t> sorts_accordance;
    std::unordered_map<size_t, std::string> array_types_accordance;
    std::vector<std::string> records;

    void batchOfTests(void (*sort)(std::vector<int>&, size_t), std::vector<int> &origin,
                      size_t n, size_t &array_type) {
        int64_t nanoseconds = 0;
        std::vector<int> working_array;
        for (int k = 0; k < TESTS_AMOUNT; ++k) {
            std::copy(origin.begin(), origin.begin() + n, std::back_inserter(working_array));

            auto start = std::chrono::high_resolution_clock::now();
            sort(working_array, n);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;

            if (!Utils::checker(working_array)) {
                std::cout << "Incorrect sort:\n";
                outputArray(working_array);
            }

            nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            working_array.clear();
        }

        records.push_back(std::to_string(n) + ";" + std::to_string(array_type) +
                          ";" + std::to_string(sorts_accordance[sort]) + ";" +
                          std::to_string(nanoseconds / TESTS_AMOUNT) + "\n");
    }

    static void makeReport(std::vector<std::string> &records) {
        std::ofstream report("/mnt/c/Users/Vlad/CLionProjects/CHW1/report.csv");
        report << "datasetSize;arrayType;sortType;time\n";
        for (auto &record : records) {
            report << record;
        }
        report.close();
    }
};

int main() {
    Tester tester;
    tester.startTests();
    return 0;
}
