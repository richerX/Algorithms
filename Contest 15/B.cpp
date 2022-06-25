#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Edge {
    int64_t begin, end, weight;
};

int64_t infinity = std::numeric_limits<int64_t>::max();
int64_t min_infinity = std::numeric_limits<int64_t>::min();
std::vector<int64_t> weights;
std::vector<Edge> edges;

// Ввод данных
int getInput() {
    int64_t n, m, a, b, w;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> w;
        edges.push_back(Edge{a, b, w});
    }
    return n;
}

// Алгоритм Беллмана-Форда
void solve(int n) {
    int m = edges.size();
    weights.assign(n, infinity);
    weights[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (weights[edges[j].begin] < infinity) {
                if (weights[edges[j].end] > weights[edges[j].begin] + edges[j].weight) {
                    weights[edges[j].end] = weights[edges[j].begin] + edges[j].weight;
                }
            }
        }
    }

    std::vector<int64_t> weights_copy(weights);
    for (int i = 0; i < n * 5; ++i) {
        for (int j = 0; j < m; ++j) {
            if (weights_copy[edges[j].begin] < infinity) {
                if (weights_copy[edges[j].end] > weights_copy[edges[j].begin] + edges[j].weight) {
                    weights_copy[edges[j].end] = weights_copy[edges[j].begin] + edges[j].weight;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (weights_copy[i] < weights[i]) {
            weights[i] = min_infinity;
        }
    }
}

void printAnswer() {
    for (int i = 1; i < weights.size(); ++i) {
        if (weights[i] == min_infinity) {
            std::cout << "-inf\n";
        } else {
            std::cout << weights[i] << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = getInput();
    solve(n);
    printAnswer();

    return 0;
}
