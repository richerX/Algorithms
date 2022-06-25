#include <iostream>
#include <string>
#include <vector>

void printVector(const std::vector<char> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string text, sub;
    std::getline(std::cin, text);
    std::getline(std::cin, sub);

    std::vector<char> dict1(256), dict2(256);

    for (int start = 0; start < text.length() - sub.length() + 1; ++start) {
        for (int i = 0; i < 256; ++i) {
            dict1[i] = 0;
            dict2[i] = 0;
        }

        bool ok = true;
        for (int i = 0; i < sub.length(); ++i) {
            if (dict1[text[i + start]] == 0 && dict2[sub[i]] == 0) {
                dict1[text[i + start]] = sub[i];
                dict2[sub[i]] = text[i + start];
            } else if (dict1[text[i + start]] != sub[i] || dict2[sub[i]] != text[i + start]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            std::cout << "Possible";
            std::cout << "\n";
            for (int i = 0; i < text.length(); ++i) {
                if (dict1[text[i]] == 0) {
                    std::cout << "?";
                } else {
                    std::cout << dict1[text[i]];
                }
            }
            return 0;
        }
    }

    std::cout << "Impossible";
    return 0;
}
