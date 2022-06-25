#include <iostream>
#include <vector>

int getAmount(const std::vector<int> &array, int length) {
    int answer = 0;
    for (auto elem : array) {
        answer += elem / length;
    }
    return answer;
}

int getMaxLength(const std::vector<int> &array, int target, int maximum) {
    int left = 1, right = maximum;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if (getAmount(array, middle) < target) {
            right = middle - 1;
        } else {
            left = middle;
        }
    }
    return getAmount(array, right) < target ? left : right;
}

int main() {
    int number, length, target, maximum = 0;
    uint64_t sum = 0;
    std::vector<int> array;
    std::cin >> length >> target;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        array.push_back(number);
        sum += number;
        if (number > maximum) {
            maximum = number;
        }
    }

    if (sum < target) {
        std::cout << 0;
    } else {
        std::cout << getMaxLength(array, target, maximum);
    }

    return 0;
}
