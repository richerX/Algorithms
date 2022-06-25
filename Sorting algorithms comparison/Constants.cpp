#include <map>
#include <string>

#include "sorts/SelectionSort.cpp"
#include "sorts/BubbleSort.cpp"
#include "sorts/BubbleSortIversonFirst.cpp"
#include "sorts/BubbleSortIversonSecond.cpp"
#include "sorts/InsertionSort.cpp"
#include "sorts/BinaryInsertionSort.cpp"
#include "sorts/CountSort.cpp"
#include "sorts/RadixSort.cpp"
#include "sorts/MergeSort.cpp"
#include "sorts/QuickSortHoar.cpp"
#include "sorts/QuickSortLomuto.cpp"
#include "sorts/HeapSort.cpp"
#include "Fillers.cpp"

std::vector<void (*)(std::vector<int> *)> sorts {selectionSort, bubbleSort,
                                                bubbleSortIversonFirst, bubbleSortIversonSecond,
                                                insertionSort, binaryInsertionSort,
                                                countSort, radixSort, mergeSort,
                                                quickSortHoar, quickSortLomuto, heapSort};

std::map<int, std::string> sorts_names = {{0, "Сортировка выбором"},
                                          {1, "Сортировка пузырьком"},
                                          {2, "Сортировка пузырьком (Айверсон 1)"},
                                          {3, "Сортировка пузырьком (Айверсон 1 + 2)"},
                                          {4, "Сортировка вставками"},
                                          {5, "Сортировка бинарными вставками"},
                                          {6, "Сортировка подсчетом"},
                                          {7, "Цифровая сортировка"},
                                          {8, "Сортировка слиянием"},
                                          {9, "Быстрая сортировка (Разбиение Хоара)"},
                                          {10, "Быстрая сортировка (Разбиение Ломуто)"},
                                          {11, "Пирамидальная сортировка"}};

std::vector<void (*)(std::vector<int> *, int)> fillers {fillRandomSmall, fillRandomBig,
                                                       fillAlmostSort, fillBackSort};

std::map<int, std::string> fillers_names = {{0, "Рандом от 0 до 5"},
                                            {1, "Рандом от 0 до 4000"},
                                            {2, "Почти отсортированный"},
                                            {3, "Отсортированный в обратном порядке"}};

std::vector<int> lengths {50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170,
                         180, 190,200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
                         400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400,
                         1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400,
                         2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400,
                         3500, 3600, 3700, 3800, 3900, 4000, 4100};
