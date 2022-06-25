#include <iostream>
#include <string>
#include <algorithm>
#include "BigIntegerUtils2.h"

BigUnsigned total = 0, k, increment;

BigUnsigned factorial(int a, int b) {
    BigUnsigned answer(1);
    for (int i = a; i <= b; ++i) {
        answer *= BigUnsigned(i);
    }
    return answer;
}

int getUnits(int n) {
    BigUnsigned count = 1;
    for (int i = n; i > 0; --i) {
        count *= BigUnsigned(i);
        if (count > k) {
            return i;
        }
    }
    return 0;
}

int getNextDigit(int series) {
    BigUnsigned amount = (k - total - 1) / increment;
    if (amount > series) {
        amount = series;
    }
    total += increment * amount;
    return amount.toInt() + 1;
}

void myPrint(int print, int series, int n) {
    std::cout << print;
    if (series != n) {
        std::cout << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, units;
    std::string position;
    std::cin >> n >> position;
    k = stringToBigUnsigned(position);

    units = getUnits(n);
    increment = factorial(units + 1, n);
    for (int series = 1; series <= n; ++series) {
        if (series < units) {
            myPrint(1, series, n);
            continue;
        }
        myPrint(getNextDigit(series), series, n);
        if (series != n) {
            increment /= (series + 1);
        }
    }

    return 0;
}
