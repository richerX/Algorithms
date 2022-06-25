#include <iostream>

int main() {
    int number = 1, first = 0, second = 0;
    while (number != 0) {
        std::cin >> number;
        if (number < 100 || number > 150) {
            continue;
        }

        if (number > first) {
            second = first;
            first = number;
        } else if (number > second) {
            second = number;
        }
    }
    std::cout << first << "\n" << second;
    return 0;
}
