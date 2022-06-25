#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int getDistanceWagner(std::string s1, std::string s2) {
    std::vector<std::vector<int>> vector(s1.length() + 1, std::vector<int>(s2.length() + 1));
    for (int i = 0; i <= s1.length(); ++i) {
        for (int j = 0; j <= s2.length(); ++j) {
            vector[i][j] = 0;
        }
    }

    for (int i = 0; i <= s1.length(); ++i) {
        vector[i][0] = i;
    }
    for (int j = 0; j <= s2.length(); ++j) {
        vector[0][j] = j;
    }

    for (int j = 1; j <= s2.length(); ++j) {
        for (int i = 1; i <= s1.length(); ++i) {
            if (s1[i - 1] == s2[j - 1]) {
                vector[i][j] = vector[i - 1][j - 1];
            } else {
                int a = vector[i - 1][j] + 1;
                int b = vector[i][j - 1] + 1;
                int c = vector[i - 1][j - 1] + 1;
                vector[i][j] = std::min(a, std::min(b, c));
            }
        }
    }

    return vector[s1.length()][s2.length()];
}

int main() {
    std::string string1, string2;
    std::cin >> string1 >> string2;
    std::cout << getDistanceWagner(string1, string2);
    return 0;
}
