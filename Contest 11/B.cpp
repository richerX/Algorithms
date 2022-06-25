#include <iostream>
#include <string>
#include <algorithm>

int backpack(const std::string &string1, const std::string &string2) {
    int array[string1.length() + 1][string2.length() + 1];
    for (int i = 0; i <= string1.length(); ++i) {
        for (int j = 0; j <= string2.length(); ++j) {
            if (i == 0 || j == 0) {
                array[i][j] = 0;
            } else if (string1[i - 1] == string2[j - 1]) {
                array[i][j] = array[i - 1][j - 1] + 1;
            } else {
                array[i][j] = std::max(array[i - 1][j], array[i][j - 1]);
            }
        }
    }
    return array[string1.length()][string2.length()];
}

int main() {
    std::string string1, string2;
    std::cin >> string1 >> string2;
    std::cout << backpack(string1, string2);
    return 0;
}
