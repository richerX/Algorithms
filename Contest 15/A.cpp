#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Edge {
public:
    int begin;
    int end;
    int weight;

    Edge(int begin, int end, int weight) {
        this->begin = begin;
        this->end = end;
        this->weight = weight;
    }
};

uint64_t infinity = std::numeric_limits<uint64_t>::max();
std::vector<bool> visited;
std::vector<uint64_t> weights;
std::vector<std::vector<Edge>> graph;

// Ввод данных
void getInput() {
    int n, m, a, b, w;
    std::cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> w;
        graph[a].push_back(Edge(a, b, w));
    }
}

// Алгоритм Дейкстры
void solve(int current) {
    visited[current] = true;
    for (auto edge : graph[current]) {
        if (!visited[edge.end]) {
            weights[edge.end] = std::min(weights[edge.end], weights[current] + edge.weight);
        }
    }

    uint64_t min_index = graph.size(), min_weight = infinity;
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i] && weights[i] < min_weight) {
            min_index = i;
            min_weight = weights[i];
        }
    }

    if (min_index != graph.size()) {
        solve(min_index);
    }
}

void solve() {
    int n = graph.size();
    visited.resize(n);
    weights.assign(n, infinity);
    weights[0] = 0;
    solve(0);
}

void printAnswer() {
    for (int i = 1; i < weights.size(); ++i) {
        std::cout << weights[i] << "\n";
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
