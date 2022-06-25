#include <vector>
#include <utility>

int upperBound(const std::vector<int> &array, int element, int end) {
    int left = 0, right = end;
    while (right - left > 0) {
        int middle = (right + left) / 2;
        if (array[middle] <= element) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

void binaryInsertionSort(std::vector<int> *vector) {
    for (int i = 1; i < vector->size(); ++i) {
        int edge = upperBound(*vector, (*vector)[i], i);
        for (int j = i; j > edge; --j) {
            std::swap((*vector)[j - 1], (*vector)[j]);
        }
    }
}
