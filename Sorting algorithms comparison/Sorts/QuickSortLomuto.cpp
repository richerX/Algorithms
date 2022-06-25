#include <vector>
#include <utility>

int getPivotLomuto(std::vector<int> *vector, int begin, int end) {
    int pivot = end;
    int index = begin;
    for (int i = begin; i < end; ++i) {
        if ((*vector)[i] <= (*vector)[pivot]) {
            std::swap((*vector)[i], (*vector)[index]);
            index++;
        }
    }
    std::swap((*vector)[pivot], (*vector)[index]);
    return index;
}

void quickSortLomutoInner(std::vector<int> *vector, int begin, int end) {
    if (begin < end) {
        int pivot = getPivotLomuto(vector, begin, end);
        quickSortLomutoInner(vector, begin, pivot - 1);
        quickSortLomutoInner(vector, pivot + 1, end);
    }
}

void quickSortLomuto(std::vector<int> *vector) {
    quickSortLomutoInner(vector, 0, vector->size() - 1);
}
