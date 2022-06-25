#include <iostream>
#include <vector>

void countSort(std::vector<int> *vector) {
    std::vector<int> helper(4'110);
    for (auto elem : *vector) {
        helper[elem] += 1;
    }

    vector->clear();
    for (int i = 0; i < helper.size(); ++i) {
        for (int j = 0; j < helper[i]; ++j) {
            vector->push_back(i);
        }
    }
}
