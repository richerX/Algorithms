#include <iostream>
#include <algorithm>
#include <vector>

int total(const std::vector<int> &internet, const std::vector<int> &apartment) {
    // 0 - apartment, 1 - internet
    std::vector<bool> internet_connection(internet.size());
    std::vector<bool> apartment_connection(internet.size());
    for (int i = 0; i < internet_connection.size(); ++i) {
        internet_connection[i] = true;
        apartment_connection[i] = false;
    }

    int complex, minimum, prev = 0;
    for (int index = 1; index < internet_connection.size(); ++index) {
        complex = internet[index] + apartment[index - 1] - internet[prev];
        minimum = std::min(std::min(internet[index], apartment[index - 1]), complex);
        if (internet[index] == minimum) {
            internet_connection[index] = true;
            apartment_connection[index - 1] = false;
            prev = index;
        } else if (apartment[index - 1] == minimum) {
            internet_connection[index] = false;
            apartment_connection[index - 1] = true;
        } else {
            internet_connection[index] = true;
            apartment_connection[index - 1] = true;
            internet_connection[prev] = false;
            prev = index;
        }
    }

    uint64_t answer = 0;
    for (int i = 0; i < internet_connection.size(); ++i) {
        answer += internet_connection[i] ? internet[i] : 0;
        answer += apartment_connection[i] ? apartment[i] : 0;
    }
    return answer;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> internet(n), apartment(n - 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> internet[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> apartment[i];
    }
    std::cout << total(internet, apartment);
    return 0;
}
