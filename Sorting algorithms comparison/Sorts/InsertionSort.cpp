#include <iostream>
#include <vector>
#include <utility>

void insertionSort(std::vector<int> *vector) {
    for (int i = 1; i < vector->size(); ++i) {
        for (int j = i - 1; j > -1; --j) {
            if ((*vector)[j] > (*vector)[j + 1]) {
                std::swap((*vector)[j], (*vector)[j + 1]);
            } else {
                break;
            }
        }
    }
}
