#include <iostream>
#include <vector>
#include <algorithm>

int getAmount(const std::vector<int> &array, int middle, int squad_size) {
    int first = 0, second = 0;
    for (int i = 0; i < array.size(); ++i) {
        second -= 1;
        if (second < 1 && array[i] <= middle) {
            first += 1;
            second = squad_size;
        }
    }
    return first;
}

int getMinDiscomfort(const std::vector<int> &array, int target, int maximum, int squad_size) {
    int left = -1, right = maximum;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if (getAmount(array, middle, squad_size) < target) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return right;
}

int main() {
    int number, people, squads, squad_size;
    std::vector<int> initial, diffs;
    std::cin >> people >> squads >> squad_size;
    for (int i = 0; i < people; ++i) {
        std::cin >> number;
        initial.push_back(number);
    }

    std::sort(initial.begin(), initial.end());
    for (int i = 0; i < people - squad_size + 1; ++i) {
        diffs.push_back(initial[i + squad_size - 1] - initial[i]);
    }

    if (squads > 1) {
        std::cout << getMinDiscomfort(diffs, squads, initial[people - 1] - initial[0], squad_size);
    } else {
        int minimum = diffs[0];
        for (int i = 0; i < diffs.size(); ++i) {
            if (diffs[i] < minimum) {
                minimum = diffs[i];
            }
        }
        std::cout << minimum;
    }

    return 0;
}
