#include <iostream>
#include <vector>

int getDigitCapacity(std::vector<int> *vector) {
    int maximum = 0;
    for (auto elem : (*vector)) {
        if (elem > maximum) {
            maximum = elem;
        }
    }

    int answer = 0;
    while (maximum > 0) {
        maximum /= 10;
        answer++;
    }
    return answer;
}

int getDigit(int number, int digit_capacity) {
    int answer = 0;
    while (digit_capacity > 0) {
        answer = number % 10;
        number /= 10;
        digit_capacity--;
    }
    return answer;
}

void radixSort(std::vector<int> *vector) {
    int digit_maximum = 10;
    int digit_capacity = getDigitCapacity(vector);

    for (int index = 1; index < digit_capacity + 1; ++index) {
        std::vector<int> digit_vector(digit_maximum);
        for (size_t j = 0; j < vector->size(); ++j) {
            digit_vector[getDigit((*vector)[j], index)]++;
        }

        int count = 0;
        for (int j = 0; j < digit_maximum; ++j) {
            int tmp = digit_vector[j];
            digit_vector[j] = count;
            count += tmp;
        }

        std::vector<int> new_vector(vector->size());
        for (size_t j = 0; j < vector->size(); ++j) {
            int shift = getDigit((*vector)[j], index);
            new_vector[digit_vector[shift]] = (*vector)[j];
            digit_vector[shift]++;
        }

        for (size_t j = 0; j < vector->size(); ++j) {
            (*vector)[j] = new_vector[j];
        }
    }
}

void printVector(const std::vector<int> &vector) {
    for (auto elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    int length, number;
    std::vector<int> vector;
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        vector.push_back(number);
    }

    radixSort(&vector);
    printVector(vector);
    return 0;
}
