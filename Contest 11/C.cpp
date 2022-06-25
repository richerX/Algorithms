#include <iostream>
#include <algorithm>
#include <vector>

void backpack(const std::vector<int> w, int max_weight) {
    int array[w.size() + 1][max_weight + 1];
    for (int i = 0; i <= w.size(); ++i) {
        for (int j = 0; j <= max_weight; ++j) {
            if (i == 0 || j == 0) {
                array[i][j] = 0;
            } else if (w[i - 1] <= j) {
                array[i][j] = std::max(array[i - 1][j], array[i - 1][j - w[i - 1]] + w[i - 1]);
            } else {
                array[i][j] = array[i - 1][j];
            }
        }
    }

    // Восстанавливаем ответ
    std::vector<int> answer;
    int stones = w.size(), weight = max_weight;
    while (array[stones][weight] != 0) {
        if (array[stones][weight] != array[stones - 1][weight]) {
            answer.push_back(w[stones - 1]);
            weight -= w[stones - 1];
        }
        stones--;
    }

    // Выводим ответ на задачу
    std::cout << array[w.size()][max_weight] << '\n';
    std::cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i > -1; --i) {
        std::cout << answer[i] << " ";
    }
}

int main() {
    int n, max_weight;
    std::cin >> n >> max_weight;
    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    backpack(w, max_weight);
    return 0;
}
