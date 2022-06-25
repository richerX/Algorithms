#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int total_loops = 0;

int getPivot(std::vector<int> *vector, int begin, int end) {
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

void quickSort(std::vector<int> *vector, int begin, int end) {
    if (begin < end) {
        int pivot = getPivot(vector, begin, end);
        quickSort(vector, begin, pivot - 1);
        quickSort(vector, pivot + 1, end);
        total_loops++;
    }
}

void fillVector(std::vector<int> *vector) {
    int length, number;
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        vector->push_back(number);
    }
}

void printVector(const std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> vector;
    fillVector(&vector);
    quickSort(&vector, 0, vector.size() - 1);
    std::cout << std::max(total_loops - 1, 0) << '\n';
    printVector(vector);
    return 0;
}
