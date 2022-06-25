#include <iostream>
#include <algorithm>

int main() {
    int r1, s1, p1, r2, s2, p2;
    std::cin >> r1 >> s1 >> p1 >> r2 >> s2 >> p2;

    int answer = 0;
    answer += std::min(r1, s2);
    answer += std::min(s1, p2);
    answer += std::min(p1, r2);
    std::cout << answer;

    return 0;
}
