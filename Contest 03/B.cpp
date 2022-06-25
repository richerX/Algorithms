#include <iostream>
#include <vector>
#include <utility>

int selectionSort(std::vector<int> *vector) {
    int swaps = 0;
    for (int i = 0; i < vector->size(); ++i) {
        int minimum = i;
        for (int j = i + 1; j < vector->size(); ++j) {
            if ((*vector)[j] < (*vector)[minimum]) {
                minimum = j;
            }
        }
        if (minimum != i) {
            swaps++;
            std::swap((*vector)[i], (*vector)[minimum]);
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

    int answer = selectionSort(&vector);
    printVector(vector);
    std::cout << answer;
    return 0;
}
