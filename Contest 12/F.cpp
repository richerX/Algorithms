#include <iostream>
#include <algorithm>
#include <vector>

void backpack(const std::vector<int> w, const std::vector<int> p, int maximum) {
    int array[w.size() + 1][maximum + 1];
    for (int i = 0; i <= w.size(); ++i) {
        for (int j = 0; j <= maximum; ++j) {
            if (i == 0 || j == 0) {
                array[i][j] = 0;
            } else if (w[i - 1] <= j) {
                array[i][j] = std::max(array[i - 1][j], array[i - 1][j - w[i - 1]] + p[i - 1]);
            } else {
                array[i][j] = array[i - 1][j];
            }
        }
    }

    // Восстанавливаем ответ
    int total_w = 0, total_p = 0;
    std::vector<int> answer_w, answer_p;
    int stones = w.size(), weight = maximum;
    while (array[stones][weight] != 0) {
        if (array[stones][weight] != array[stones - 1][weight]) {
            total_p += p[stones - 1];
            answer_p.push_back(p[stones - 1]);
            total_w += w[stones - 1];
            answer_w.push_back(w[stones - 1]);
            weight -= w[stones - 1];
        }
        stones--;
    }

    // Выводим ответ на задачу
    std::cout << total_p << '\n';
    std::cout << total_w << '\n';
    std::cout << answer_w.size() << '\n';
    for (int i = answer_w.size() - 1; i > -1; --i) {
        std::cout << answer_w[i] << " ";
    }
    std::cout << "\n";
    for (int i = answer_p.size() - 1; i > -1; --i) {
        std::cout << answer_p[i] << " ";
    }
}

int main() {
    int n, max_weight;
    std::cin >> n >> max_weight;
    std::vector<int> w(n), p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    backpack(w, p, max_weight);
    return 0;
}
