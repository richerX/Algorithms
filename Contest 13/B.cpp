#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void printSortedNames(const std::vector<std::string> &names,
                      const std::vector<std::vector<int>> &edges, int head) {
    std::vector<bool> visited(names.size());
    std::vector<int> current_indexes{head};
    std::vector<std::string> current_names;
    std::vector<int> next_indexes;
    visited[head] = true;

    while (!current_indexes.empty()) {
        current_names.clear();
        for (auto index : current_indexes) {
            current_names.push_back(names[index]);
        }
        std::sort(current_names.begin(), current_names.end());
        for (auto name : current_names) {
            std::cout << name << '\n';
        }

        next_indexes.clear();
        for (auto index : current_indexes) {
            for (auto next_index : edges[index]) {
                if (!visited[next_index]) {
                    next_indexes.push_back(next_index);
                    visited[next_index] = true;
                }
            }
        }

        current_indexes.clear();
        for (auto next_index : next_indexes) {
            current_indexes.push_back(next_index);
        }
    }
}

template <typename T>
void printVector(const std::vector<T> &vector, const std::string &separator = "\n") {
    for (auto elem : vector) {
        std::cout << elem << separator;
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, number, a, b, head;
    std::cin >> n >> m;
    std::vector<std::string> names(n);
    std::vector<std::vector<int>> edges(n);
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
    printSortedNames(names, edges, head);
    return 0;
}
