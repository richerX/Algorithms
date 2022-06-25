#include <iostream>
#include <vector>

int lowerBound(const std::vector<int> &array, int element) {
    int left = 0, right = array.size();
    while (right - left > 0) {
        int middle = (right + left) / 2;
        if (array[middle] < element) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int upperBound(const std::vector<int> &array, int element) {
    int left = 0, right = array.size();
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

int main() {
    int number, first_length, second_length;
    std::vector<int> first, second;
    std::cin >> first_length >> second_length;
    for (int i = 0; i < first_length + second_length; ++i) {
        std::cin >> number;
        i < first_length ? first.push_back(number) : second.push_back(number);
    }

    for (int element : second) {
        int lower = lowerBound(first, element), upper = upperBound(first, element);
        if (first[lower] == element) {
            std::cout << lower + 1 << " " << upper << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }

    return 0;
}
