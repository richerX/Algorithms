#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <string>

void printDictionary(const std::unordered_map<std::string, char> &dictionary) {
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int letters, length;
    std::string encoded, letter, code;
    std::unordered_map<std::string, std::string> dictionary;

    std::cin >> letters >> length;
    for (int i = 0; i < letters; ++i) {
        std::cin >> letter >> code;
        dictionary[code] = letter.substr(0, 1);
    }
    std::cin >> encoded;

    std::string current;
    for (char digit : encoded) {
        current += digit;
        if (dictionary.find(current) != dictionary.end()) {
            std::cout << dictionary[current];
            current = "";
        }
    }

    return 0;
}
