#include <iostream>
#include <vector>

std::vector<bool> visited;
std::vector<std::vector<int>> graph;
std::vector<std::vector<bool>> answer;
 
void dfs(int current) {
    if (visited[current]) {
        return;
    }
    visited[current] = true;
    for (int i = 0; i < graph[current].size(); ++i) {
        dfs(graph[current][i]);
        answer[current][i] = true;
//        std::cout << current + 1 << " " << graph[current][i] + 1 << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, input1, input2;
    std::cin >> n >> m;
    visited.assign(n, false);
    for (int i = 0; i < n; ++i) {
        graph.push_back(std::vector<int>());
        answer.push_back(std::vector<bool>());
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> input1 >> input2;
        graph[input1 - 1].push_back(input2 - 1);
        answer[input1 - 1].push_back(false);
    }

    for (int i = 0; i < graph.size(); ++i) {
        visited.assign(n, false);
        dfs(i);
    }

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            if (answer[i][j]) {
                std::cout << i + 1 << " " << graph[i][j] + 1 << "\n";
            }
        }
    }

    return 0;
}