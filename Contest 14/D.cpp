#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> answer;
std::vector<bool> origin;
std::vector<bool> visited;
std::vector<std::string> names;
std::vector<std::vector<int>> graph;

void dfs(int v) {
    visited[v] = true;
    for (size_t i = 0; i < graph[v].size(); ++i) {
        if (!visited[graph[v][i]]) {
            dfs(graph[v][i]);
        }
    }
    answer.push_back(v);
}

bool compare(int first, int second) {
    return (names[first] < names[second]);
}

int getInput() {
    int n, m, a, b;
    std::string name;
    std::cin >> n >> m;
    origin.assign(n, true);
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        std::cin.get();
        std::getline(std::cin, name);
        names.push_back(name);
    }
    for (int i = 0; i < n; ++i) {
        graph.push_back(std::vector<int>());
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        origin[b - 1] = false;
    }
    for (int i = 0; i < n; ++i) {
        std::sort(graph[i].begin(), graph[i].end(), compare);
    }
    return n;
}

// Реализован алгоритм Тарьяна
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = getInput();

    std::vector<int> origins;
    for (int i = 0; i < n; ++i) {
        if (origin[i]) {
            origins.push_back(i);
        }
    }
    std::sort(origins.begin(), origins.end(), compare);

    visited.assign(n, false);
    for (auto i : origins) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = answer.size() - 1; i > -1; --i) {
        std::cout << names[answer[i]] << "\n";
    }
}
