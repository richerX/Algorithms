#include <iostream>
#include <vector>

void printPalindrome(std::vector<int> *vector) {
    for (int i = 0; i < vector->size(); ++i) {
        for (int j = 0; j < (*vector)[i] / 2; ++j) {
            std::cout << static_cast<char>('A' + i);
        }
    }

    for (int i = 0; i < vector->size(); ++i) {
        if ((*vector)[i] % 2 == 1) {
            std::cout << static_cast<char>('A' + i);
            break;
        }
    }

    for (int i = vector->size() - 1; i > -1; --i) {
        for (int j = 0; j < (*vector)[i] / 2; ++j) {
            std::cout << static_cast<char>('A' + i);
        }
    }
}

int main() {
    int length;
    char letter;
    std::vector<int> vector(26);
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> letter;
        vector[letter - 'A']++;
    }
    printPalindrome(&vector);
    return 0;
}
