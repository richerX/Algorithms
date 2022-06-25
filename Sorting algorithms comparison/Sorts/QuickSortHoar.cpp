#include <vector>
#include <utility>

std::pair<int, int> getPivotHoar(std::vector<int> *vector, int begin, int end) {
    int pivot = (*vector)[(begin + end) / 2];
    while (begin <= end) {
        while ((*vector)[begin] < pivot) {
            begin++;
        }
        while ((*vector)[end] > pivot) {
            end--;
        }
        if (begin <= end) {
            std::swap((*vector)[begin++], (*vector)[end--]);
        }
    }
    return std::pair<int, int>(begin, end);
}

void quickSortHoarInner(std::vector<int> *vector, int begin, int end) {
    if (begin < end) {
        auto pivot = getPivotHoar(vector, begin, end);
        quickSortHoarInner(vector, begin, pivot.second);
        quickSortHoarInner(vector, pivot.first, end);
    }
}

void quickSortHoar(std::vector<int> *vector) {
    quickSortHoarInner(vector, 0, vector->size() - 1);
}
