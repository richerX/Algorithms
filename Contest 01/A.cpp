#include <iostream>
#include <list>

int main() {
    int count, number;
    std::list<int> array;

    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        std::cin >> number;
        array.push_back(number);
    }

    int answer = 0;
    bool found = true;
    while (found) {
        found = false;
        for (auto iter = array.begin(); iter != array.end(); ++iter) {
            int row = 0;
            auto next = iter;
            while (*iter == *next) {
                row++;
                if (next == array.end()) {
                    next++;
                    break;
                }
                next++;
            }

            if (row >= 3) {
                array.erase(iter, next);
                answer += row;
                found = true;
                break;
            }
        }
    }

    std::cout << answer;
    return 0;
}
