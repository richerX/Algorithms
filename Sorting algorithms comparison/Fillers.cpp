#include <vector>
#include <utility>

// Случайные значения от 0 до 5
void fillRandomSmall(std::vector<int> *base, int length) {
    base->clear();
    for (int i = 0; i < length; ++i) {
        base->push_back(rand() % 6);
    }
}

// Случайные значения от 0 до 4000
void fillRandomBig(std::vector<int> *base, int length) {
    base->clear();
    for (int i = 0; i < length; ++i) {
        base->push_back(rand() % 4001);
    }
}

// Почти отсортированный
void fillAlmostSort(std::vector<int> *base, int length) {
    base->clear();
    for (int i = 0; i < length; ++i) {
        base->push_back(i + 1);
    }
    for (int i = 0; i < length / 50; ++i) {
        std::swap((*base)[rand() % length], (*base)[rand() % length]);
    }
}

// Отсортированный в обратном порядке
void fillBackSort(std::vector<int> *base, int length) {
    base->clear();
    for (int i = 0; i < length; ++i) {
        base->push_back(length - i);
    }
}
