#include <iostream>
#include <algorithm>
#include <vector>

class Item {
public:
    double weight;
    double price;

    double rate() const {
        return price / weight;
    }

    void print() {
        std::cout << "w = " << weight << ", p = " << price << ", rate = " << rate() << '\n';
    }
};

bool compare(const Item &a, const Item &b) {
    if (a.rate() == b.rate()) {
        return (a.weight > b.weight);
    }
    return a.rate() > b.rate();
}

void backpack(const std::vector<Item> vector, int maximum) {
    int current_weight = 0, total_weight = 0, total_price = 0;
    std::vector<int> weights, prices;
    for (int i = 0; i < vector.size(); ++i) {
        if (current_weight + vector[i].weight <= maximum) {
            total_weight += vector[i].weight;
            total_price += vector[i].price;
            weights.push_back(vector[i].weight);
            prices.push_back(vector[i].price);
            current_weight += vector[i].weight;
        }
    }

    // Выводим ответ на задачу
    std::cout << total_price << '\n';
    std::cout << total_weight << '\n';
    std::cout << weights.size() << '\n';
    for (int i = weights.size() - 1; i > -1; --i) {
        std::cout << weights[i] << " ";
    }
    std::cout << "\n";
    for (int i = prices.size() - 1; i > -1; --i) {
        std::cout << prices[i] << " ";
    }
}

int main() {
    int n, maximum;
    std::cin >> n >> maximum;
    std::vector<Item> vector(n);
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> (i < n ? vector[i].weight : vector[i - n].price);
    }
    std::sort(vector.begin(), vector.end(), compare);

    for (auto elem : vector) {
        elem.print();
    }

    backpack(vector, maximum);
    return 0;
}
