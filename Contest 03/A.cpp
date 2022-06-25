#include <iostream>
#include <vector>
#include <utility>

int bubbleSort(std::vector<int> *vector) {
    int swaps = 0;
    for (int i = 0; i < vector->size(); ++i) {
        for (int j = 0; j < vector->size() - i - 1; ++j) {
            if ((*vector)[j] > (*vector)[j + 1]) {
                swaps++;
                std::swap((*vector)[j], (*vector)[j + 1]);
            }
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

    int answer = bubbleSort(&vector);
    printVector(vector);
    std::cout << answer;
    return 0;
}
