#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int getDistanceDamerauLevenshtein(const std::string &s1, const std::string &s2) {
    std::vector<std::vector<int>> vector(s1.length() + 1, std::vector<int>(s2.length() + 1));
    for (int i = 0; i < s1.length() + 1; ++i) {
        vector[i][0] = i;
    }
    for (int j = 0; j < s2.length() + 1; ++j) {
        vector[0][j] = j;
    }

    for (int i = 1; i < s1.length() + 1; ++i) {
        for (int j = 1; j < s2.length() + 1; ++j) {
            int a = vector[i - 1][j] + 1;
            int b = vector[i][j - 1] + 1;
            int c = vector[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1);
            vector[i][j] = std::min(a, std::min(b, c));
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                vector[i][j] = std::min(vector[i][j], vector[i - 2][j - 2] + 1);
            }
        }
    }

    return vector[s1.length()][s2.length()];
}

int main() {
    int loops;
    std::cin >> loops;
    std::string string1, string2;
    for (int i = 0; i < loops; ++i) {
        std::cin >> string1 >> string2;
        std::cout << getDistanceDamerauLevenshtein(string1, string2);
        if (i < loops - 1) {
            std::cout << " ";
        }
    }
    return 0;
}
