#include <iostream>
#include "BigIntegerUtils2.h"

BigUnsigned factorial(int a, int b) {
    BigUnsigned answer(1);
    for (int i = a; i <= b; ++i) {
        answer *= BigUnsigned(i);
    }
    return answer;
}

BigUnsigned combinations(int n, int k) {
    if (k > n / 2) {
        return combinations(n, n - k);
    }
    return factorial(n - k + 1, n) / factorial(1, k);
}

BigUnsigned pairs(int n) {
    BigUnsigned pairs(1);
    for (int i = 2; i <= n; i += 2) {
        pairs *= combinations(i, 2);
    }
    return pairs / factorial(1, n / 2);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << factorial(1, n) << '\n';
    std::cout << combinations(n, k) << '\n';
    std::cout << pairs(n) << '\n';
    return 0;
}
