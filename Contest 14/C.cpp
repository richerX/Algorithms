#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<bool> visited;
std::vector<std::string> names;
std::vector<int> order, component;
std::vector<std::vector<int>> graph, reverse;

void dfs(int v) {
    visited[v] = true;
    for (size_t i = 0; i < graph[v].size(); ++i) {
        if (!visited[graph[v][i]]) {
            dfs(graph[v][i]);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < reverse[v].size(); ++i) {
        if (!visited[reverse[v][i]]) {
            dfs2(reverse[v][i]);
        }
    }
}

int getInput() {
    int n, m, a, b;
    std::string name;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        std::cin.get();
        std::getline(std::cin, name);
        names.push_back(name);
    }
    for (int i = 0; i < n; ++i) {
        graph.push_back(std::vector<int>());
        reverse.push_back(std::vector<int>());
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        graph[a].push_back(b);
        reverse[b].push_back(a);
    }
    return n;
}

bool compare(const std::vector<std::string> &first, const std::vector<std::string> &second) {
    return (first[0] < second[0]);
}

// Реализован алгоритм Косарайю
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = getInput();

    visited.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    visited.assign(n, false);
    std::vector<std::vector<std::string>> answer;
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!visited[v]) {
            dfs2(v);
            answer.push_back(std::vector<std::string>());
            for (auto elem : component) {
                answer[answer.size() - 1].push_back(names[elem]);
            }
            component.clear();
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        std::sort(answer[i].begin(), answer[i].end());
    }
    std::sort(answer.begin(), answer.end(), compare);

    for (auto vector : answer) {
        for (auto elem : vector) {
            std::cout << elem << "\n";
        }
        std::cout << "\n";
    }
}
