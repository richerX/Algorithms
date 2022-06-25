#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int total_loops = 0;

std::pair<int, int> getPivot(std::vector<int> *vector, int begin, int end) {
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

void quickSort(std::vector<int> *vector, int begin, int end) {
    if (begin < end) {
        auto pivot = getPivot(vector, begin, end);
        quickSort(vector, begin, pivot.second);
        quickSort(vector, pivot.first, end);
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
