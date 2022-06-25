#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int infinity = std::numeric_limits<int>::max();
std::vector<bool> visited;
std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> destinations;

void getInput() {
    int n, m, a, b, w;
    std::cin >> n >> m;
    graph.assign(n, std::vector<int>(n));
    destinations.assign(n, std::vector<int>(n));
    visited.assign(n, false);
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> w;
        graph[a - 1][b - 1] = w;
        destinations[a - 1].push_back(b - 1);
        destinations[b - 1].push_back(a - 1);
    }
}

int findPath(int start, int finish, int weight) {
    if (start == finish) {
        return weight;
    }

    visited[start] = true;
    for (int index : destinations[start]) {
        if (!visited[index] && graph[start][index] > 0) {
            int df = findPath(index, finish, std::min(weight, graph[start][index]));
            if (df > 0) {
                graph[start][index] -= df;
                graph[index][start] += df;
                return df;
            }
        }
    }

    return 0;
}

// https://sites.google.com/site/indy256/algo/ford_fulkerson
int maxFlow() {
    int flow = 0, df = 1;
    while (df != 0) {
        for (int i = 0; i < graph.size(); ++i) {
            visited[i] = false;
        }
        df = findPath(0, graph.size() - 1, infinity);
        flow += df;
    }
    return flow;
}

int main() {
    getInput();
    std::cout << maxFlow();
    return 0;
}
