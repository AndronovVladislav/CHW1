#include "chw1.h"

int main() {
    std::vector<void (*)(std::vector<int>&, size_t)> sorts({selectionSort, bubbleSort,
                                                       bubbleSortIverson1, bubbleSortIverson1_2,
                                                       insertionSort, binaryInsertionSort,
                                                       stableCountingSort, radixSort,
                                                       mergeSort, quickSort, heapSort,
                                                       shellShellSort, shellCiuraSort});
    std::vector<std::string> sorts_names({"selectionSort", "bubbleSort",
                                               "bubbleSortIverson1", "bubbleSortIverson1_2",
                                               "insertionSort", "binaryInsertionSort",
                                               "stableCountingSort", "radixSort",
                                               "mergeSort", "quickSort", "heapSort",
                                               "shellShellSort", "shellCiuraSort"});

    std::vector<std::vector<int>> origins({DatasetGenerator::generateRandomArray(0, 5),
                              DatasetGenerator::generateRandomArray(0, 4000),
                              DatasetGenerator::almostSortedArray(0, 4000),
                              DatasetGenerator::reversedSortedArray(0, 4100)});

    std::vector<std::string> origins_names({"random_0-5", "random_0-4000",
                                            "almostSorted", "reversedSorted"});

    std::vector<int> working_array;
    std::vector<std::string> records;

    int64_t nanoseconds;
    for (size_t i = 0; i < sorts.size(); ++i) {
//        std::cout << "I'm started " + sorts_names[i] + " testing:" << std::endl;
        for (auto size : SMALL_SIZES) {
            nanoseconds = 0;
//            std::cout << "on " << size << " size:\n";
            for (size_t j = 0; j < origins.size(); ++j) {
//                std::cout << "on " << j << " type: ";
                for (int k = 0; k < TESTS_AMOUNT; ++k) {
                    std::copy(origins[j].begin(), origins[j].begin() + size, std::back_inserter(working_array));

                    auto start = std::chrono::high_resolution_clock::now();
                    sorts[i](working_array, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    if (!checker(working_array)) {
                        std::cout << "Incorrect sort:\n";
                        outputArray(working_array);
                        return 0;
                    }

                    nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    working_array.clear();
                }

                records.push_back(std::to_string(size) + ";" + origins_names[j] + ";" + sorts_names[i] + ";" +
                                          std::to_string(nanoseconds / TESTS_AMOUNT) + "\n");
//                report << size << ";" << origins_names[j] << ";" << sorts_names[i] << ";" << nanoseconds / TESTS_AMOUNT << ";" << '\n';
            }
        }

        for (auto size : LARGE_SIZES) {
            nanoseconds = 0;
//            std::cout << "on " << size << " size:\n";
            for (size_t j = 0; j < origins.size(); ++j) {
//                std::cout << "on " << j << " type: ";
                for (int k = 0; k < TESTS_AMOUNT; ++k) {
                    std::copy(origins[j].begin(), origins[j].begin() + size, std::back_inserter(working_array));

                    auto start = std::chrono::high_resolution_clock::now();
                    sorts[i](working_array, size);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;

                    if (!checker(working_array)) {
                        std::cout << "Incorrect sort:\n";
                        outputArray(working_array);
                        return 0;
                    }

                    nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                    working_array.clear();
                }

                records.push_back(std::to_string(size) + ";" + origins_names[j] + ";" + sorts_names[i] + ";" +
                                  std::to_string(nanoseconds / TESTS_AMOUNT) + "\n");
//                report << size << ";" << origins_names[j] << ";" << sorts_names[i] << ";" << nanoseconds / TESTS_AMOUNT << ";" << '\n';
            }
        }
    }

    std::ofstream report("/mnt/c/Users/Vlad/CLionProjects/CHW1/report.csv");
    for (size_t i = 0; i < records.size(); ++i) {
        report << records[i];
    }
    report.close();

    return 0;
}