#include <iostream>
#include <unordered_map>
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

    std::string current;
    int length, prev, number;
    std::cin >> length;
    std::unordered_map<std::string, int> encoding;
    std::unordered_map<int, std::string> decoding;
    for (int i = 0; i < 128; ++i) {
        encoding[std::string(1, static_cast<char>(i))] = i;
        decoding[i] = std::string(1, static_cast<char>(i));
    }

    std::cin >> number;
    std::cout << decoding[number];
    prev = number;
    for (int emp = 1; emp < length; ++emp) {
        std::cin >> number;

        // Восстанавливаем строку, которая кодировалась на прошлом шаге
        // Она состоит из предыдущей строки + первой буквы текущей строки

        // Но иногда первую букву текущей строки найти сложно
        // Это происходит в случаях, когда мы сразу же используем код появившейся на прошло шаге
        // Например, строка 'aaa' -> поэтому первый символ строки с еще неизвестным нам кодом
        // Совпадает с первым символом предыдущей строки
        current = decoding[prev];
        if (number >= decoding.size()) {
            current += decoding[prev].substr(0, 1);
        } else {
            current += decoding[number].substr(0, 1);
        }

        if (encoding.find(current) == encoding.end()) {
            encoding[current] = encoding.size();
            decoding[decoding.size()] = current;
        }

        std::cout << decoding[number];

        prev = number;
    }

    return 0;
}
