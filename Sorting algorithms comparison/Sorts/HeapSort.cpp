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
    for (int i = vector->size() / 2 - 1; i >= 0; --i) {
        heapify(vector, vector->size(), i);
    }
    for (int i = vector->size() - 1; i >= 0; --i) {
        std::swap((*vector)[0], (*vector)[i]);
        heapify(vector, i);
    }
}
