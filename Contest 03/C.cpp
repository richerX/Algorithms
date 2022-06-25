#include <iostream>
#include <vector>
#include <utility>

int insertionSort(std::vector<int> *vector) {
    int indicator = 0;
    for (int i = 1; i < vector->size(); ++i) {
        for (int j = i - 1; j > -1; --j) {
            if ((*vector)[j] > (*vector)[j + 1]) {
                std::swap((*vector)[j], (*vector)[j + 1]);
            } else {
                indicator += j == i - 1 ? 1 : 0;
                break;
            }
        }
    }
    return indicator;
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

    int answer = insertionSort(&vector);
    printVector(vector);
    std::cout << answer;
    return 0;
}
