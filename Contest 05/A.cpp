#include <iostream>
#include <vector>

int getAnswer(const std::vector<int> &vector) {
    for (int i = 1; i < vector.size(); ++i) {
        if (vector[(i - 1) / 2] < vector[i]) {
            return i - 1;
        }
    }
    return vector.size() - 1;
}

int main() {
    int length, number;
    std::vector<int> vector;
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        vector.push_back(number);
    }

    std::cout << getAnswer(vector);
    return 0;
}
