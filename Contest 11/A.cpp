#include <iostream>
#include <string>

int crossings(const std::string &string, int position = 0, bool on_left_side = true) {
    if (position == string.length()) {
        return on_left_side ? 1 : 0;
    }

    // Простые ситуации
    if (string[position] == 'L' && !on_left_side) {
        return crossings(string, position + 1, on_left_side);
    } else if (string[position] == 'R' && on_left_side) {
        return crossings(string, position + 1, on_left_side);
    }

    // Ситуации в самом конце пути
    if (position == string.length() - 1) {
        if (string[position] == 'L' && on_left_side) {
            return crossings(string, position + 1, !on_left_side) + 1;
        } else if (string[position] == 'R' && !on_left_side) {
            return crossings(string, position + 1, on_left_side) + 1;
        }
    }

    // Двойные ситуации
    if (string[position] == 'L' && string[position + 1] == 'L' && on_left_side) {
        return crossings(string, position + 2, !on_left_side) + 1;
    } else if (string[position] == 'L' && string[position + 1] == 'R' && on_left_side) {
        return crossings(string, position + 2, on_left_side) + 1;
    } else if (string[position] == 'R' && string[position + 1] == 'R' && !on_left_side) {
        return crossings(string, position + 2, !on_left_side) + 1;
    } else if (string[position] == 'R' && string[position + 1] == 'L' && !on_left_side) {
        return crossings(string, position + 2, on_left_side) + 1;
    }

    return 0;
}

int main() {
    std::string input, string;
    std::cin >> input;

    int both_count = 0;
    for (auto elem : input) {
        if (elem == 'B') {
            both_count++;
        } else {
            string += elem;
        }
    }

    std::cout << crossings(string) + both_count;
    return 0;
}
