#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

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

void readVector(std::vector<int> *vector) {
    int number;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream stream(input);
    while (stream >> number) {
        vector->push_back(number);
    }
}

void printVector(const std::vector<int> &vector) {
    for (auto elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> kilometers, prices;
    readVector(&kilometers);
    readVector(&prices);

    binaryInsertionSort(&kilometers);
    binaryInsertionSort(&prices);
    uint64_t total = 0;
    for (int i = 0; i < prices.size(); ++i) {
        total += prices[i] * kilometers[kilometers.size() - i - 1];
    }

    std::cout << total;
    return 0;
}
