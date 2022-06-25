#include <iostream>
#include <string>
#include <vector>

bool correct(const std::vector<int> &vector, const std::vector<int> &evenness, int k) {
    int current, previous, count;
    for (int index = 0; index < vector.size() / k; ++index) {
        current = (index + 1) * (k + 1) - 1;
        previous = index * (k + 1) - 1;

        if (current < evenness.size()) {
            count = evenness[current];
            if (previous > -1) {
                count += evenness[previous] + vector[previous];
            }
            if (count % 2 != vector[current]) {
                return false;
            }
        }
    }
    return true;
}

void printVector(const std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int length;
    std::string input;
    std::cin >> length >> input;

    // Ввод преобразовать в вектор
    std::vector<int> vector(input.size());
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '1') {
            vector[i] = 1;
        }
    }

    // Четность суммы всех элементов до данного
    std::vector<int> evenness(input.size());
    for (int i = 1; i < input.size(); ++i) {
        evenness[i] = (evenness[i - 1] + vector[i - 1]) % 2;
    }

    // Подсчет ответа
    int answer = 0;
    for (int k = 1; k < input.size(); ++k) {
        if (correct(vector, evenness, k)) {
            answer++;
        }
    }

    std::cout << answer;
    return 0;
}
