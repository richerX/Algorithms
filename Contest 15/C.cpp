#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

uint64_t infinity = std::numeric_limits<uint64_t>::max();
std::vector<std::vector<uint64_t>> graph;

// Ввод данных
void getInput() {
    int n, m, a, b, w;
    std::cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        graph[i].assign(n, infinity);
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> w;
        graph[a][b] = w;
    }
}

// Алгоритм Флойда-Уоршелла
void solve() {
    int n = graph.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != infinity && graph[k][j] != infinity) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

void printAnswer() {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (graph[i][j] == infinity) {
                    std::cout << i << " " << j << " " << -1 << "\n";
                } else {
                    std::cout << i << " " << j << " " << graph[i][j] << "\n";
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    getInput();
    solve();
    printAnswer();

    return 0;
}
