#include <iostream>
#include <vector>

void merge(std::vector<int> *vector, int start1, int end1, int start2, int end2) {
    int start = start1;
    std::vector<int> helper;
    helper.reserve(end2 - start1 + 1);

    while (start1 <= end1 && start2 <= end2) {
        if ((*vector)[start1] <= (*vector)[start2]) {
            helper.push_back((*vector)[start1]);
            start1++;
        } else {
            helper.push_back((*vector)[start2]);
            start2++;
        }
    }

    while (start1 <= end1) {
        helper.push_back((*vector)[start1]);
        start1++;
    }
    while (start2 <= end2) {
        helper.push_back((*vector)[start2]);
        start2++;
    }

    for (int i = start; i <= end2; ++i) {
        (*vector)[i] = helper[i - start];
    }
}

void mergeSort(std::vector<int> *vector, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int middle = begin + (end - begin) / 2;
    mergeSort(vector, begin, middle);
    mergeSort(vector, middle + 1, end);
    merge(vector, begin, middle, middle + 1, end);
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
    mergeSort(&vector, 0, vector.size() - 1);
    printVector(vector);
    return 0;
}
