#include <iostream>
#include <vector>
#include <string>

void getPrefixes(const std::string &string, std::vector<int> *vector) {
    for (int i = 0; i < string.length(); ++i) {
        vector->push_back(0);
    }

    int value = 0;
    for (int i = 1; i < string.length(); ++i) {
        while (value > 0 && string[i] != string[value]) {
            value = (*vector)[value - 1];
        }
        value += string[i] == string[value] ? 1 : 0;
        (*vector)[i] = value;
    }
}

void printVector(const std::vector<int> &vector) {
    for (auto elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> vector;
    std::string string;
    std::cin >> string;
    getPrefixes(string, &vector);

    printVector(vector);
    return 0;
}
