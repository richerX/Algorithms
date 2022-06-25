#include <iostream>
#include <vector>
#include <algorithm>

int cut(const std::vector<int> &vector) {
    int array[vector.size()][vector.size()];
    for (int i = 0; i < vector.size(); ++i) {
        for (int j = 0; j < vector.size(); ++j) {
            array[i][j] = 0;
        }
    }

    for (int j = 1; j < vector.size(); ++j) {
        for (int i = j - 2; i > -1; --i) {
            array[i][j] = 2'147'483'647;
            for (int k = i + 1; k < j; ++k) {
                array[i][j] = std::min(array[i][j], array[i][k] + array[k][j]);
            }
            array[i][j] += vector[j] - vector[i];
        }
    }
    return array[0][vector.size() - 1];
}

int main() {
    int length, incisions, number;
    std::cin >> length >> incisions;

    std::vector<int> vector;
    vector.push_back(0);
    for (int i = 0; i < incisions; ++i) {
        std::cin >> number;
        vector.push_back(number);
    }
    vector.push_back(length);

    std::cout << cut(vector);
    return 0;
}
