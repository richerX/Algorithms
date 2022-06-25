#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

int main() {
    int count, window, number;
    std::vector<int> array;
    std::cin >> count >> window;
    for (int i = 0; i < count; ++i) {
        std::cin >> number;
        array.push_back(number);
    }

    int minimum = -1, index = -1;
    for (int cur = 0; cur < count - window + 1; ++cur) {
        if (cur > index) {
            minimum = array[cur];
            index = cur;
            for (int i = cur; i < cur + window; ++i) {
                if (i >= count) {
                    break;
                }
                if (array[i] < minimum) {
                    minimum = array[i];
                    index = i;
                }
            }
        } else {
            int new_index = cur + window - 1;
            if (array[new_index] < minimum) {
                minimum = array[new_index];
                index = new_index;
            }
        }
        std::cout << minimum << "\n";
    }

    return 0;
}
