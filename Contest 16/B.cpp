#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>

int infinity = std::numeric_limits<int>::max();
std::vector<bool> visited;
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> graph;

void getInput() {
    int n, m, a, b, c, d;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b >> c >> d;
        auto key = std::pair<int, int> (a, b);
        auto value = std::pair<int, int> (c, d);
        if (graph.find(key) == graph.end()) {
            graph[key] =
        }
        graph[key].push_back(value);
    }
}

int findPath(int start, int finish, int weight) {
    if (start == finish) {
        return weight;
    }

    visited[start] = true;
    for (int index = 0; index < visited.size(); ++index) {
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

int maxFlow() {
    int flow = 0, df = 1;
    while (df != 0) {
        visited.assign(graph.size(), false);
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
