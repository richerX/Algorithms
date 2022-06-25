#include <iostream>
#include <algorithm>
#include <vector>

uint64_t chess(std::vector<std::vector<uint64_t>> *vector, int i, int j) {
    if (i < 0 || i >= (*vector).size() || j < 0 || j >= (*vector)[0].size()) {
        return 0;
    }
    if ((*vector)[i][j] == -1) {
        uint64_t sum = 0;
        sum += chess(vector, i - 2, j - 1);
        sum += chess(vector, i - 2, j + 1);
        sum += chess(vector, i - 1, j - 2);
        sum += chess(vector, i + 1, j - 2);
        (*vector)[i][j] = sum;
    }
    return (*vector)[i][j];
}

uint64_t run(int n, int m) {
    std::vector<std::vector<uint64_t>> vector(n, std::vector<uint64_t>(m, -1));
    vector[0][0] = 1;
    return chess(&vector, n - 1, m - 1);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << run(n, m);
    return 0;
}
