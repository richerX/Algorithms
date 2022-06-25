#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string string;
    std::cin >> string;

    int error = 0;
    for (int i = 0; i < string.size(); ++i) {
        if (string[i] == '1') {
            error ^= i + 1;
        }
    }
    error--;

    int power = 1;
    for (int index = 0; index < string.size(); ++index) {
        if (index + 1 == power) {
            power *= 2;
        } else if (error == index) {
            if (string[error] == '1') {
                std::cout << '0';
            } else {
                std::cout << '1';
            }
        } else {
            std::cout << string[index];
        }
    }

    return 0;
}
