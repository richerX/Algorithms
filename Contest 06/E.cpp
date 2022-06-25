#include <iostream>
#include <vector>
#include <utility>

uint64_t getValue(int blue, int green, int red) {
    uint64_t first = blue - green;
    uint64_t second = blue - red;
    uint64_t third = green - red;
    return first * first + second * second + third * third;
}

void printAnswer(const std::vector<int> &vector1, const std::vector<int> &vector2,
                 const std::vector<int> &vector3) {
    std::vector<int> answer{vector1[0], vector2[0], vector3[0]};
    uint64_t minimum = getValue(vector1[0], vector2[0], vector3[0]), current;

    for (int i = 0; i < vector1.size(); ++i) {
        for (int j = 0; j < vector2.size(); ++j) {
            for (int k = 0; k < vector3.size(); ++k) {
                current = getValue(vector1[i], vector2[j], vector3[k]);
                if (current < minimum) {
                    minimum = current;
                    answer = {vector1[i], vector2[j], vector3[k]};
                }
            }
        }
    }

    std::cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
}

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
    }
}

void fillVector(std::vector<int> *vector, int length) {
    int number;
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int total, first, second, third;
    std::vector<int> vector1, vector2, vector3;
    std::cin >> total;
    for (int index = 0; index < total; ++index) {
        std::cin >> first >> second >> third;
        fillVector(&vector1, first);
        fillVector(&vector2, second);
        fillVector(&vector3, third);

        quickSort(&vector1, 0, vector1.size() - 1);
        quickSort(&vector2, 0, vector2.size() - 1);
        quickSort(&vector3, 0, vector3.size() - 1);

        printAnswer(vector1, vector2, vector3);

        vector1.clear();
        vector2.clear();
        vector3.clear();
    }

    return 0;
}
