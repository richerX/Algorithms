#include <iostream>
#include <vector>
#include <utility>

void heapify(std::vector<int> *vector, int begin, int index = 0) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Находим максимум
    int maximum = index;
    maximum = left < begin && (*vector)[left] > (*vector)[maximum] ? left : maximum;
    maximum = right < begin && (*vector)[right] > (*vector)[maximum] ? right : maximum;

    // Проталкиваем больший элемент в корень
    if (maximum != index) {
        std::swap((*vector)[index], (*vector)[maximum]);
        heapify(vector, begin, maximum);
    }
}

void heapSort(std::vector<int> *vector) {
    // Создание кучи
    for (int i = vector->size() / 2 - 1; i >= 0; --i) {
        heapify(vector, vector->size(), i);
    }
    // Преобразование кучи поэлементно
    for (int i = vector->size() - 1; i >= 0; --i) {
        std::swap((*vector)[0], (*vector)[i]);
        heapify(vector, i);
    }
}

int lowerBound(const std::vector<int> &array, int element) {
    int left = 0, right = array.size();
    while (right - left > 0) {
        int middle = (right + left) / 2;
        if (array[middle] < element) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int upperBound(const std::vector<int> &array, int element) {
    int left = 0, right = array.size();
    while (right - left > 0) {
        int middle = (right + left) / 2;
        if (array[middle] <= element) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

void fillVectors(std::vector<int> *vector1, std::vector<int> *vector2) {
    int length, number1, number2;
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> number1 >> number2;
        vector1->push_back(number1);
        vector2->push_back(number2 + 1);
    }
}

int getAnswer(int number, const std::vector<int> &vector1, const std::vector<int> &vector2) {
    int opened = upperBound(vector1, number);
    int closed = upperBound(vector2, number);
    return opened - closed;
}

int main() {
    std::vector<int> vector1, vector2;
    fillVectors(&vector1, &vector2);
    heapSort(&vector1);
    heapSort(&vector2);

    int number;
    char symbol;
    std::cin >> symbol;
    while (symbol != '!') {
        std::cin >> number;
        std::cout<< "! " << getAnswer(number, vector1, vector2) << std::endl << std::flush;
        std::cin >> symbol;
    }

    return 0;
}
