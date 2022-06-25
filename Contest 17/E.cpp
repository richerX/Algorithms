#include <iostream>
#include <vector>
#include "BigUnsigned2.h"

void printBigUnsigned(BigUnsigned number) {
    std::vector<int> answer;
    while (number > 0) {
        answer.push_back((number % 10).toInt());
        number /= 10;
    }
    for (int i = answer.size() - 1; i > -1; --i) {
        std::cout << answer[i];
    }
}

BigUnsigned combinations(int n, int k) {
    if (k > n / 2) {
        return combinations(n, n - k);
    }

    BigUnsigned answer(1);
    for (int i = 1; i <= k; ++i) {
        answer *= (n - i + 1);
        answer /= i;
    }

    return answer;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    printBigUnsigned(combinations(n + k, n));
    return 0;
}
