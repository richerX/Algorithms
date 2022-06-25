#include <iostream>
#include <string>

uint64_t total = 0;
uint64_t max_k = 1'000'001;

uint64_t power(int a, int b) {
    uint64_t answer = 1;
    if (a == 1 || b == 0) {
        return answer;
    }
    for (int i = 0; i < b; ++i) {
        answer *= a;
        if (answer > max_k) {
            return answer;
        }
    }
    return answer;
}

int getNextDigit(int n, uint64_t k, uint64_t increment) {
    for (int digit = 1; digit <= n; ++digit) {
        total += increment;
        if (total >= k) {
            total -= increment;
            return digit;
        }
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    for (int series = 1; series <= m; ++series) {
        std::cout << getNextDigit(n, k, power(n, m - series));
        if (series != m) {
            std::cout << " ";
        }
    }

    return 0;
}
