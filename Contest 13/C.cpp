#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printVector(const std::vector<T> &vector, const std::string &separator = "\n") {
    for (auto elem : vector) {
        std::cout << elem << separator;
    }
    std::cout << "\n";
}

void printSortedNames(const std::vector<std::string> &names,
                      const std::vector<std::vector<int>> &edges, std::vector<bool> *visited,
                      int current) {
    if ((*visited)[current]) {
        return;
    }

    std::cout << names[current] << "\n";
    (*visited)[current] = true;

    for (auto index : edges[current]) {
        if (!(*visited)[index]) {
            printSortedNames(names, edges, visited, index);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, number, a, b, head;
    std::cin >> n >> m;
    std::vector<std::string> names(n);
    std::vector<std::vector<int>> edges(n);
    std::vector<bool> visited(names.size());
    for (int i = 0; i < n; ++i) {
        std::cin >> number;
        std::cin.get();
        std::getline(std::cin, names[i]);
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    std::cin >> head;

    for (int i = 0; i < edges.size(); ++i) {
        std::sort(edges[i].begin(), edges[i].end(),
                  [&](int i, int j) -> bool { return names[i] < names[j]; });
    }

    printSortedNames(names, edges, &visited, head);
    return 0;
}
