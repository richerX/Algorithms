#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
    int count, total_threshold, univ_threshold, number;
    std::vector<int> numbers;
    std::vector<std::string> teams;
    std::unordered_map<std::string, int> map;

    std::string university;
    std::cin >> count >> total_threshold >> univ_threshold;
    std::getline(std::cin, university);
    for (int i = 0; i < count; ++i) {
        std::getline(std::cin, university);
        teams.push_back(university);
        map[university] = 0;
    }
    for (int i = 0; i < count; ++i) {
        std::cin >> number;
        numbers.push_back(number);
    }

    int printed = 0;
    for (int cur = 0; cur < count; ++cur) {
        if (map.find(teams[cur])->second < univ_threshold) {
            map[teams[cur]]++;
            printed++;
            std::cout << teams[cur] << " #" << numbers[cur] << "\n";
        }
        if (printed >= total_threshold) {
            break;
        }
    }

    return 0;
}
