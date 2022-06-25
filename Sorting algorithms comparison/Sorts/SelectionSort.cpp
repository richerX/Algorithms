#include <vector>
#include <utility>

void selectionSort(std::vector<int> *vector) {
    for (int i = 0; i < vector->size(); ++i) {
        int minimum = i;
        for (int j = i + 1; j < vector->size(); ++j) {
            if ((*vector)[j] < (*vector)[minimum]) {
                minimum = j;
            }
        }
        if (minimum != i) {
            std::swap((*vector)[i], (*vector)[minimum]);
        }
    }
}
