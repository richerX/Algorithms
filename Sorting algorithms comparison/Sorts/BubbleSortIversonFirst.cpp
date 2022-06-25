#include <vector>
#include <utility>

void bubbleSortIversonFirst(std::vector<int> *vector) {
    for (int i = 0; i < vector->size(); ++i) {
        bool changed = false;
        for (int j = 0; j < vector->size() - i - 1; ++j) {
            if ((*vector)[j] > (*vector)[j + 1]) {
                changed = true;
                std::swap((*vector)[j], (*vector)[j + 1]);
            }
        }
        if (!changed) {
            return;
        }
    }
}
