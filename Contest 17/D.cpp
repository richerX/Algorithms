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

BigUnsigned factorial(int a, int b) {
    BigUnsigned answer(1);
    for (int i = a; i <= b; ++i) {
        answer *= BigUnsigned(i);
    }
    return answer;
}

BigUnsigned combinations(int n, int k) {
    int a = k, b = n - k;
    if (n - k > k) {
        a = n - k;
        b = k;
    }
    return factorial(a + 1, n) / factorial(1, b);
}

int getNextDigit(int n, int last_digit, int empty_slots, BigUnsigned k) {
    BigUnsigned increment;
    for (int digit = last_digit + 1; digit <= n; ++digit) {
        increment = combinations(n - digit, empty_slots);
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
    int n, m, last_digit = 0;
    std::string position;
    std::cin >> n >> position >> m;

    used.resize(n + 1);
    BigUnsigned k = stringToBigUnsigned(position);
    for (int series = 1; series <= m; ++series) {
        last_digit = getNextDigit(n, last_digit, m - series, k);
        std::cout << last_digit;
        if (series != m) {
            std::cout << " ";
        }
    }

    return 0;
}
