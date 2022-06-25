#include <iostream>
#include <vector>
#include <string>
#include "BigIntegerUtils2.h"

BigUnsigned total = 0;
std::vector<bool> used;

BigUnsigned specialFactorial(int start, int length) {
    BigUnsigned answer(1);
    for (int i = 0; i < length; ++i) {
        answer *= BigUnsigned(start - i);
    }
    return answer;
}

int getNextDigit(int n, BigUnsigned k, BigUnsigned increment) {
    for (int digit = 1; digit <= n; ++digit) {
        if (!used[digit]) {
            total += increment;
            if (total >= k) {
                total -= increment;
                used[digit] = true;
                return digit;
            }
        }
    }
    return n;
}

int main() {
    int n, m;
    std::string position;
    std::cin >> n >> m >> position;

    used.resize(n + 1);
    BigUnsigned k = stringToBigUnsigned(position);
    BigUnsigned increment = specialFactorial(n - 1, m - 1);
    for (int series = 1; series <= m; ++series) {
        std::cout << getNextDigit(n, k, increment);
        if (series != m) {
            std::cout << " ";
            increment /= n - series;
        }
    }

    return 0;
}
