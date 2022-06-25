#include <iostream>
#include <vector>
#include <string>

void printPositions(const std::string &str, const std::string &sub) {
    std::vector<int> edges(sub.length()), perfect_edges(sub.length());
    for (int i = 0; i < sub.length(); ++i) {
        edges.push_back(0);
        perfect_edges.push_back(0);
    }

    int value = 0;
    for (int i = 1; i < sub.length(); ++i) {
        while (value > 0 && sub[i] != sub[value]) {
            value = edges[value - 1];
        }
        value += sub[i] == sub[value] ? 1 : 0;
        edges[i] = value;
    }

    for (int i = 1; i < sub.length(); ++i) {
        if (sub[edges[i]] != sub[i + 1]) {
            perfect_edges[i] = edges[i];
        } else {
            perfect_edges[i] = perfect_edges[edges[i]];
        }
    }

    int current = 0;
    std::vector<int> positions;
    for (int i = 0; i < str.length(); ++i) {
        while (current > 0 && sub[current] != str[i]) {
            current = perfect_edges[current - 1];
        }
        current += sub[current] == str[i] ? 1 : 0;
        if (current == sub.length()) {
            positions.push_back(i - sub.length() + 1);
        }
    }

    std::cout << positions.size() << '\n';
    for (auto elem : positions) {
        std::cout << elem << '\n';
    }
}

void printVector(const std::vector<int> &vector) {
    for (auto elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

int main() {
    std::string string, substring;
    std::cin >> substring >> string;
    printPositions(string, substring);
    return 0;
}
