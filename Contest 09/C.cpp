#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int getNumberOfCorrectors(int size) {
    int correctors = 1, power = 2;
    while (power < correctors + size + 1) {
        correctors++;
        power *= 2;
    }
    return correctors;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string string;
    std::cin >> string;
    std::vector<int> vector(getNumberOfCorrectors(string.size()));
    std::vector<int> powers{1,       2,       4,       8,       16,     32,     64,
                            128,     256,     512,     1024,    2048,   4096,   8192,
                            16384,   32768,   65536,   131072,  262144, 524288, 1048576,
                            2097152, 4194304, 8388608, 16777216};

    int shift = 1;
    for (int index = 0; index < string.size(); ++index) {
        if (index + shift == powers[shift - 1]) {
            shift++;
            index--;
            continue;
        }

        if (string[index] == '1') {
            for (int i = 0; i < vector.size(); ++i) {
                int table_index = index + shift;
                if (table_index > powers[i] && (table_index / powers[i]) % 2 == 1) {
                    vector[i]++;
                }
            }
        }
    }

    shift = 1;
    for (int index = 0; index < string.size(); ++index) {
        if (index + shift == powers[shift - 1]) {
            std::cout << vector[shift - 1] % 2;
            shift++;
            index--;
            continue;
        }
        std::cout << string[index];
    }

    return 0;
}
