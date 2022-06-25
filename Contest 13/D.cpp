#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> field;
std::vector<std::vector<int>> delta{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                    {1, -2},  {1, 2},  {2, -1},  {2, 1}};

void run(int n) {
    int x, y;
    std::cin >> x >> y;
    std::queue<int> queue_x, queue_y;

    queue_x.push(x);
    queue_y.push(y);
    field[x][y] = 0;

    // Итеративный BFS
    while (!queue_x.empty()) {
        int first = queue_x.front();
        int second = queue_y.front();
        queue_x.pop();
        queue_y.pop();
        for (int d = 0; d < delta.size(); ++d) {
            int first_d = first + delta[d][0];
            int second_d = second + delta[d][1];
            bool in_field = first_d > 0 && first_d <= n && second_d > 0 && second_d <= n;
            if (in_field && field[first_d][second_d] > field[first][second] + 1) {
                field[first_d][second_d] = field[first][second] + 1;
                queue_x.push(first_d);
                queue_y.push(second_d);
            }
        }
    }

    // Вывод ответа
    std::cin >> x >> y;
    std::cout << field[x][y] << "\n";

    // Восстановление ходов
    int cur_x = x, cur_y = y;
    std::vector<std::vector<int>> path{{x, y}};
    for (int emp = 0; emp < field[x][y]; ++emp) {
        for (int d = 0; d < delta.size(); ++d) {
            int prev_x = cur_x + delta[d][0];
            int prev_y = cur_y + delta[d][1];
            bool in_field = prev_x > 0 && prev_x <= n && prev_y > 0 && prev_y <= n;
            if (in_field && field[prev_x][prev_y] + 1 == field[cur_x][cur_y]) {
                path.push_back(std::vector<int>{prev_x, prev_y});
                cur_x = prev_x;
                cur_y = prev_y;
                continue;
            }
        }
    }

    // Вывод ходов
    for (int i = path.size() - 1; i > -1; --i) {
        std::cout << path[i][0] << " " << path[i][1] << "\n";
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; ++i) {
        field.push_back(std::vector<int>());
        for (int j = 0; j <= n; ++j) {
            field[i].push_back(2'147'483'647);
        }
    }
    run(n);
    return 0;
}
