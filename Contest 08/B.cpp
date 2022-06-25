#include <iostream>
#include <vector>
#include <string>

int getAnswer(const std::string &string) {
    std::vector<int> vector;
    for (int i = 0; i < string.length(); ++i) {
        vector.push_back(0);
    }

    int value = 0, answer = 1;
    for (int i = 1; i < string.length(); ++i) {
        while (value > 0 && string[i] != string[value]) {
            value = vector[value - 1];
        }
        value += string[i] == string[value] ? 1 : 0;
        vector[i] = value;
        if (i - value + 1 > answer) {
            answer = i - value + 1;
        }
    }

    return vector.size() - vector[vector.size() - 1];
}

int main() {
    std::string string;
    std::getline(std::cin, string);
    std::cout << getAnswer(string);
    return 0;
}
