#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

void printMap(const std::unordered_map<std::string, int> &map) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it->second > 50) {
            std::cout << it->first << ": " << it->second << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string string;
    std::getline(std::cin, string);
    std::unordered_map<std::string, int> table;
    std::vector<int> fragments;
    for (int i = 0; i < 128; ++i) {
        table[std::string(1, static_cast<char>(i))] = i;
    }

    std::string current = std::string(1, string[0]);
    for (int i = 1; i < string.size(); ++i) {
        if (table.find(current + string[i]) == table.end()) {
            table[current + string[i]] = table.size();
            fragments.push_back(table[current]);
            current.clear();
        }
        current += string[i];
    }
    fragments.push_back(table[current]);

    std::cout << fragments.size() << "\n";
    for (int i = 0; i < fragments.size(); ++i) {
        std::cout << fragments[i] << " ";
    }

    return 0;
}
