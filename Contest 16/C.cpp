#include <iostream>

int main() {
    auto a = std::pair<int, int> (1, 2);
    auto b = std::pair<int, int> (1, 2);
    std::cout << (a == b);
    return 0;
}
