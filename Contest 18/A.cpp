#include <iostream>
#include <vector>

std::vector<int> tents(12);

void displayTents() {
    for (int i = tents.size() - 1; i > -1; --i) {
        for (int j = 0; j < tents[i]; ++j) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << "\n";
}

int search(bool dismiss_last) {
    bool found_last = false;
    for (int i = 0; i < tents.size(); ++i) {
        if (tents[i] > 0) {
            if (dismiss_last && !found_last && tents[i] == 1) {
                found_last = true;
                continue;
            }
            return i;
        }
    }
    return -1;
}

void solve() {
    displayTents();
    int minimum = 0, last, total;
    while (minimum < tents.size() - 1) {
        minimum = search(true);
        if (minimum == tents.size() - 1 || minimum == -1) {
            return;
        }
        tents[minimum + 1]++;
        tents[minimum]--;

        last = search(false);
        tents[last]--;
        if (last - 1 >= 0) {
            tents[last - 1]++;
        }

        total = 0;
        for (int j = 0; j <= minimum; ++j) {
            total += tents[j] * (j + 1);
            tents[j] = 0;
        }
        tents[0] = total;

        displayTents();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    tents[0] = n;
    solve();
    return 0;
}
