#include <iostream>
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

int binaryInsertionSort(std::vector<int> *vector) {
    int swaps = 0;
    for (int i = 1; i < vector->size(); ++i) {
        int edge = upperBound(*vector, (*vector)[i], i);
        for (int j = i; j > edge; --j) {
            swaps++;
            std::swap((*vector)[j - 1], (*vector)[j]);
        }
    }
    return swaps;
}

void printVector(const std::vector<int> &vector) {
    for (auto elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    int length, number;
    std::vector<int> vector;
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        vector.push_back(number);
    }

    int answer = binaryInsertionSort(&vector);
    printVector(vector);
    std::cout << answer;
    return 0;
}
