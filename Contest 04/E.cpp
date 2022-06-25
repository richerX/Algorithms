#include <iostream>
#include <vector>

int main() {
    int number, buttons, presses;
    std::vector<int> capacity;

    // Считывание прочности клавиш
    std::cin >> buttons;
    for (int i = 0; i < buttons; ++i) {
        std::cin >> number;
        capacity.push_back(number);
    }

    // Считывание нажатий
    std::cin >> presses;
    for (int i = 0; i < presses; ++i) {
        std::cin >> number;
        capacity[number - 1]--;
    }

    // Вывод состояния клавиш
    for (int i = 0; i < buttons; ++i) {
        std::cout << (capacity[i] < 0 ? "yes" : "no") << "\n";
    }
    return 0;
}
