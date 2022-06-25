#include <iostream>
#include <vector>

const int kMaxSize = 2'000'001;

void countSort(std::vector<int> *vector, std::vector<int> *answer) {
    for (auto elem : *vector) {
        (*answer)[elem + kMaxSize / 2] += 1;
    }
}

void specialPrintVector(const std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        for (int j = 0; j < vector[i]; ++j) {
            std::cout << i - kMaxSize / 2 << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    int length, number;
    std::vector<int> vector, answer(kMaxSize);
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        vector.push_back(number);
    }

    countSort(&vector, &answer);
    specialPrintVector(answer);
    return 0;
}
