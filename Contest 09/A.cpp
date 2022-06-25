#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

int findMinimum(const std::vector<std::pair<int, std::string>> &table) {
    int minimum = 0;
    for (int i = 1; i < table.size(); ++i) {
        if (table[i].first < table[minimum].first) {
            minimum = i;
        }
    }
    return minimum;
}

std::string encode(const std::string &initial, const std::map<char, std::string> &dictionary) {
    std::string answer = std::string();
    for (char letter : initial) {
        answer += dictionary.at(letter);
    }
    return answer;
}

void printDictionary(const std::map<char, std::string> &dictionary) {
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}

void printPairVector(const std::vector<std::pair<int, std::string>> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i].first << " " << vector[i].second << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> count(26);
    std::map<char, std::string> dictionary;
    std::vector<std::pair<int, std::string>> table;
    std::string string = "abroad";
    std::cin >> string;

    // Чтение строки
    for (char letter : string) {
        count[letter - 'a']++;
        dictionary[letter] = std::string();
    }

    // Создание алфавита
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        if (count[letter - 'a'] > 0) {
            std::pair<int, std::string> new_value(count[letter - 'a'], std::string(1, letter));
            table.push_back(new_value);
        }
    }

    // Создание словаря
    while (table.size() > 1) {
        int new_int = 0;
        std::string new_str = std::string();
        for (int i = 1; i > -1; --i) {
            int minimum = findMinimum(table);
            new_int += table[minimum].first;
            new_str = table[minimum].second + new_str;
            for (char letter : table[minimum].second) {
                dictionary[letter] = std::to_string(i) + dictionary[letter];
            }
            table.erase(table.begin() + minimum);
        }
        table.push_back(std::pair<int, std::string>(new_int, new_str));
    }
    if (dictionary.size() == 1) {
        dictionary[dictionary.begin()->first] = "0";
    }

    // Вывод
    std::string encoded = encode(string, dictionary);
    std::cout << dictionary.size() << " " << encoded.size() << "\n";
    printDictionary(dictionary);
    std::cout << encoded << "\n"
              << "\n";

    return 0;
}
