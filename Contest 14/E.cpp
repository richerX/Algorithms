#include <iostream>
#include <vector>

std::vector<bool> visited;
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

void printComponent() {
    for (auto elem : component) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    int n, m, a, b;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        graph.push_back(std::vector<int>());
        reverse.push_back(std::vector<int>());
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        reverse[b - 1].push_back(a - 1);
    }

    visited.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    visited.assign(n, false);
    std::vector<int> answer(n);
    int current_component = 1;
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!visited[v]) {
            dfs2(v);
            for (auto elem : component) {
                answer[elem] = current_component;
            }
            component.clear();
            current_component++;
        }
    }

    std::cout << current_component - 1 << "\n";
    for (auto elem : answer) {
        std::cout << elem << " ";
    }
}
