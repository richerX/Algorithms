#include <vector>
#include <utility>

void bubbleSortIversonSecond(std::vector<int> *vector) {
    int prev_swap_maximum = vector->size() - 1;
    for (int i = 0; i < vector->size(); ++i) {
        int swap_maximum = 0;
        for (int j = 0; j < prev_swap_maximum; ++j) {
            if ((*vector)[j] > (*vector)[j + 1]) {
                swap_maximum = j + 1;
                std::swap((*vector)[j], (*vector)[j + 1]);
            }
        }
        prev_swap_maximum = swap_maximum;
        if (swap_maximum == 0) {
            return;
        }
    }
}
