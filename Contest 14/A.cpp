#include <iostream>
#include <vector>
#include <map>

std::map<int, int> map;
std::vector<bool> visited;
std::vector<int> order, component;
std::vector<std::vector<int>> graph, reverse;

// Алгоритм Косарайю
void dfs1(int v) {
    visited[v] = true;
    for (size_t i = 0; i < graph[v].size(); ++i) {
        if (!visited[graph[v][i]]) {
            dfs1(graph[v][i]);
        }
    }
    order.push_back(v);
}

// Алгоритм Косарайю
void dfs2(int v) {
    visited[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < reverse[v].size(); ++i) {
        if (!visited[reverse[v][i]]) {
            dfs2(reverse[v][i]);
        }
    }
}

// Заполнить вектор order для алгоритма Косарайю
int fillOrder() {
    visited.assign(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    return 0;
}

// Заполнить map цветов
int fillMap() {
    visited.assign(graph.size(), false);
    int color = 0;
    for (int i = 0; i < graph.size(); ++i) {
        int v = order[graph.size() - i - 1];
        if (!visited[v]) {
            dfs2(v);
            for (int j = 0; j < component.size(); ++j) {
                map[component[j]] = color;
            }
            color++;
            component.clear();
        }
    }
    return color;
}

// Поиск ответа
void solve(int colors) {
    std::vector<int> answer(colors);
    for (int i = 0; i < graph.size(); ++i) {
        answer[map[i]]++;
        for (int j = 0; j < graph[i].size(); ++j) {
            if (map[i] != map[graph[i][j]]) {
                answer[map[i]] = 2'000'000'000;
            }
        }
    }

    // Поиск минимума
    int v = 0;
    for (int i = 1; i < colors; ++i) {
        if (answer[i] < answer[v]) {
            v = i;
        }
    }

    // Вывод ответа
    std::cout << answer[v] << "\n";
    for (int i = 0; i < graph.size(); ++i) {
        if (map[i] == v) {
            std::cout << i + 1 << " ";
        }
    }
}

// Ввод данных
int getInput() {
    int n, m, h, a, b;
    std::cin >> n >> m >> h;
    std::vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }

    for (int i = 0; i < n; ++i) {
        graph.push_back(std::vector<int>());
        reverse.push_back(std::vector<int>());
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        if ((input[a - 1] + 1) % h == input[b - 1]) {
            graph[a - 1].push_back(b - 1);
            reverse[b - 1].push_back(a - 1);
        }
        if ((input[b - 1] + 1) % h == input[a - 1]) {
            reverse[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }
    }
    return n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    getInput();
    fillOrder();
    int colors = fillMap();
    solve(colors);

    return 0;
}
