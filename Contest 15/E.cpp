#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

struct Edge {
    int begin, end, weight;
};

int n, start, finish;
uint64_t infinity = std::numeric_limits<uint64_t>::max();
std::vector<bool> visited;
std::vector<int> previous;
std::vector<uint64_t> weights;
std::vector<std::vector<Edge>> graph;

// Ввод данных
void getInput() {
    std::cin >> n >> start >> finish;
    graph.resize(n + 1);
    visited.resize(n + 1);
    previous.assign(n + 1, -1);
    weights.assign(n + 1, infinity);
    weights[start] = 0;
}

int getCost(int number) {
    int cost = 0;
    while (number > 0) {
        cost += number % 10;
        number /= 10;
    }
    return cost;
}

void fillGraph(int current) {
    std::string number = std::to_string(current);
    for (int len = 1; len <= number.length(); ++len) {
        for (int begin = 0; begin + len <= number.length(); ++begin) {
            int delta = stoi(number.substr(begin, len));
            if (current + delta <= n) {
                graph[current].push_back(Edge{current, current + delta, getCost(delta)});
            }
            if (current - delta > 0 && delta != 0) {
                graph[current].push_back(Edge{current, current - delta, getCost(delta)});
            }
        }
    }
}

// Алгоритм Дейкстры
void solve(int current) {
    visited[current] = true;

    if (graph[current].empty()) {
        fillGraph(current);
    }

    for (auto edge : graph[current]) {
        if (!visited[edge.end] && weights[current] + edge.weight < weights[edge.end]) {
            weights[edge.end] = weights[current] + edge.weight;
            previous[edge.end] = current;
        }
    }

    if (current == finish) {
        return;
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

void printAnswer() {
    if (weights[finish] == infinity) {
        std::cout << -1 << "\n";
        return;
    }

    std::vector<int> path;
    int current = finish;
    while (previous[current] != -1) {
        path.push_back(current);
        current = previous[current];
    }
    path.push_back(start);

    std::cout << weights[finish] << "\n";
    std::cout << path.size() - 1 << "\n";
    for (int i = path.size() - 1; i > 0; --i) {
        int delta = path[i - 1] - path[i];
        if (delta > 0) {
            std::cout << "+" << delta << "\n";
        } else {
            std::cout << delta << "\n";
        }
    }
}

void printGraph() {
    for (auto vector : graph) {
        for (auto edge : vector) {
            std::cout << edge.begin << " -> " << edge.end << " (" << edge.weight << ")\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    getInput();
    solve(start);
    printAnswer();

    return 0;
}
