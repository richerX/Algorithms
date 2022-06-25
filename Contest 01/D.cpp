#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <set>

int getHeight(std::string name, const std::map<std::string, std::string> &tree) {
    auto iter = tree.find(name);
    if (iter == tree.end()) {
        return 0;
    } else {
        return getHeight(iter->second, tree) + 1;
    }
}

int main() {
    int count;
    std::string child, parent;
    std::set<std::string> names;
    std::map<std::string, int> height;
    std::map<std::string, std::string> tree;

    std::cin >> count;
    for (int i = 0; i < count - 1; ++i) {
        std::cin >> child >> parent;
        tree.insert(std::make_pair(child, parent));
        names.insert(child);
        names.insert(parent);
    }

    for (auto iter = names.begin(); iter != names.end(); ++iter) {
        std::cout << *iter << " " << getHeight(*iter, tree) << "\n";
    }

    return 0;
}
