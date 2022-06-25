#include <iostream>
#include <cmath>
#include <iomanip>

double getAnswer(double target) {
    double left = 0, right = target;
    while (right - left > 0.000000001) {
        double middle = (left + right) / 2;
        if (middle * middle + sqrt(middle) < target) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return left;
}

int main() {
    double number;
    std::cin >> number;
    std::cout << std::fixed << std::setprecision(10) << getAnswer(number);
    return 0;
}
