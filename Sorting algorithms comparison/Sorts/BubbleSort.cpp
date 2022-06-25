#include <vector>
#include <utility>

void bubbleSort(std::vector<int> *vector) {
    for (int i = 0; i < vector->size(); ++i) {
        for (int j = 0; j < vector->size() - i - 1; ++j) {
            if ((*vector)[j] > (*vector)[j + 1]) {
                std::swap((*vector)[j], (*vector)[j + 1]);
            }
        }
    }
}
