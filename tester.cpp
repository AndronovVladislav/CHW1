#include "chw1.h"

class Tester {
public:
    Tester() {
        sorts = {
                selectionSort, bubbleSort, bubbleSortAiverson1, bubbleSortAiversonAll,
                insertionSort, binaryInsertionSort, stableCountingSort, radixSort,
                mergeSort, quickSort, heapSort, shellShellSort, shellCiuraSort
        };

        operationsCheckers = {
                selectionSortOperations, bubbleSortOperations, bubbleSortAiverson1Operations,
                bubbleSortAiversonAllOperations, insertionSortOperations,
                binaryInsertionSortOperations, stableCountingSortOperations, radixSortOperations,
                mergeSortOperations, quickSortOperations, heapSortOperations,
                shellShellSortOperations, shellCiuraSortOperations
        };

        sortsAccordance = {
                {selectionSort,          "selectionSort"         },
                {bubbleSort,            "bubbleSort"            },
                {bubbleSortAiverson1,   "bubbleSortAiverson1"   },
                {bubbleSortAiversonAll, "bubbleSortAiversonAll" },
                {insertionSort,         "insertionSort"         },
                {binaryInsertionSort,   "binaryInsertionSort"   },
                {stableCountingSort,    "stableCountingSort"    },
                {radixSort,             "radixSort"             },
                {mergeSort,             "mergeSort"             },
                {quickSort,             "quickSort"             },
                {heapSort,              "heapSort"              },
                {shellShellSort,        "shellShellSort"        },
                {shellCiuraSort,        "shellCiuraSort"        }
        };

        operationsCheckersAccordance = {
                {selectionSortOperations,         "selectionSort"         },
                {bubbleSortOperations,            "bubbleSort"            },
                {bubbleSortAiverson1Operations,   "bubbleSortAiverson1"   },
                {bubbleSortAiversonAllOperations, "bubbleSortAiversonAll" },
                {insertionSortOperations,         "insertionSort"         },
                {binaryInsertionSortOperations,   "binaryInsertionSort"   },
                {stableCountingSortOperations,    "stableCountingSort"    },
                {radixSortOperations,             "radixSort"             },
                {mergeSortOperations,             "mergeSort"             },
                {quickSortOperations,             "quickSort"             },
                {heapSortOperations,              "heapSort"              },
                {shellShellSortOperations,        "shellShellSort"        },
                {shellCiuraSortOperations,        "shellCiuraSort"        }
        };

        origins = {Utils::generateRandomArray(0, 5), Utils::generateRandomArray(0, 4000),
                   Utils::almostSortedArray(0, 4000), Utils::reversedSortedArray(0, 4100)};
    }

    void startTests() {
        for (int i = 0; i < sorts.size(); ++i) {
            std::cout << "Time tests completed: " << (i * 100) / sorts.size() << "%" << std::endl;
            for (auto size : SMALL_SIZES) {
                for (size_t j = 0; j < origins.size(); ++j) {
                    operationsTest(operationsCheckers[i], origins[j], size, j);
                    batchOfTimeTests(sorts[i], origins[j], size, j);
                }
            }

            for (auto size : LARGE_SIZES) {
                for (size_t j = 0; j < origins.size(); ++j) {
                    operationsTest(operationsCheckers[i], origins[j], size, j);
                    batchOfTimeTests(sorts[i], origins[j], size, j);
                }
            }
        }

        makeTimeReport(timeRecords);
        makeOperationsReport(operationsRecords);
    }
private:
    std::vector<void (*)(std::vector<int>&, size_t)> sorts;
    std::vector<void (*)(std::vector<int>&, size_t, int64_t&)> operationsCheckers;

    std::unordered_map<void (*)(std::vector<int>&, size_t), std::string> sortsAccordance;
    std::unordered_map<void (*)(std::vector<int>&, size_t, int64_t&),
                       std::string> operationsCheckersAccordance;

    std::vector<std::vector<int>> origins;
    std::vector<std::string> timeRecords;
    std::vector<std::string> operationsRecords;

    void batchOfTimeTests(void (*sort)(std::vector<int>&, size_t), std::vector<int> &origin,
                      size_t n, size_t &array_type) {
        int64_t nanoseconds = 0;
        std::vector<int> working_array;
        for (int k = 0; k < TESTS_AMOUNT; ++k) {
            std::copy(origin.begin(), origin.begin() + n, std::back_inserter(working_array));

            auto start = std::chrono::high_resolution_clock::now();
            sort(working_array, n);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;

            if (!Utils::checker(working_array)) {
                std::cout << "Incorrect " + sortsAccordance[sort] + ":\n";
                Utils::outputArray(working_array);
                return;
            }

            nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            working_array.clear();
        }

        timeRecords.push_back(std::to_string(n) + ";" + Utils::getArrayTypename(array_type) +
                          ";" + sortsAccordance[sort] + ";" +
                          std::to_string(nanoseconds / TESTS_AMOUNT) + "\n");
    }

    void operationsTest(void (*checker)(std::vector<int>&, size_t, int64_t&), std::vector<int> &origin,
                      size_t n, size_t &array_type) {
        std::vector<int> working_array;
        std::copy(origin.begin(), origin.begin() + n, std::back_inserter(working_array));

        int64_t result;
        checker(working_array, n, result);

        if (!Utils::checker(working_array)) {
            std::cout << "Incorrect" + operationsCheckersAccordance[checker] + "sort:\n";
            Utils::outputArray(working_array);
            return;
        }

        operationsRecords.push_back(std::to_string(n) + ";" + Utils::getArrayTypename(array_type) +
                          ";" + operationsCheckersAccordance[checker] + ";" +
                          std::to_string(result) + "\n");
    }

    static void makeTimeReport(std::vector<std::string> &records) {
        std::ofstream report("/mnt/c/Users/Vlad/CLionProjects/CHW1/report_time.csv");
        report << "datasetSize;arrayType;sortType;time\n";
        for (auto &record : records) {
            report << record;
        }
        report.close();
    }

    static void makeOperationsReport(std::vector<std::string> &records) {
        std::ofstream report("/mnt/c/Users/Vlad/CLionProjects/CHW1/report_operations.csv");
        report << "datasetSize;arrayType;sortType;operations\n";
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
