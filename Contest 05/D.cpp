#include <iostream>
#include <vector>
#include <utility>

struct Pair {
    int value;
    int id;

    Pair(int value, int id) {
        this->value = value;
        this->id = id;
    }
};

void heapify(std::vector<Pair> *vector, int begin, int index = 0) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Находим максимум
    int maximum = index;
    maximum = left < begin && (*vector)[left].value > (*vector)[maximum].value ? left : maximum;
    maximum = right < begin && (*vector)[right].value > (*vector)[maximum].value ? right : maximum;

    // Проталкиваем больший элемент в корень
    if (maximum != index) {
        std::swap((*vector)[index], (*vector)[maximum]);
        heapify(vector, begin, maximum);
    }
}

void heapSort(std::vector<Pair> *vector) {
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

int lowerBound(const std::vector<Pair> &vector, int element) {
    int left = 0, right = vector.size();
    while (right - left > 0) {
        int middle = (right + left) / 2;
        if (vector[middle].value < element) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

void fillVector(std::vector<Pair> *vector) {
    int length, number;
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        vector->push_back(Pair(number, i));
    }
}

void printVector(const std::vector<Pair> &vector) {
    std::cout << "ID     ";
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i].id << " ";
    }
    std::cout << "\n";

    std::cout << "VALUES ";
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i].value << " ";
    }
    std::cout << "\n";
}

int getNearby(const std::vector<Pair> &shelters, int village_value) {
    int nearby = lowerBound(shelters, village_value);
    if (nearby == 0) {
        return shelters[nearby].id;
    } else if (nearby == shelters.size()) {
        return shelters[nearby - 1].id;
    }

    int dist1 = std::abs(village_value - shelters[nearby].value);
    int dist2 = std::abs(village_value - shelters[nearby - 1].value);
    if (dist1 < dist2) {
        return shelters[nearby].id;
    }
    return shelters[nearby - 1].id;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<Pair> villages, shelters;
    fillVector(&villages);
    fillVector(&shelters);
    heapSort(&shelters);

    for (int i = 0; i < villages.size(); ++i) {
        std::cout << getNearby(shelters, villages[i].value) + 1 << " ";
    }

    return 0;
}
