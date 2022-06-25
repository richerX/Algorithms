#include <iostream>

int ask(int left, int right) {
    int answer = 0;
    if (left != right) {
        std::cout<< "? " << left << " " << right << std::endl << std::flush;
        std::cin >> answer;
    }
    return answer;
}

int getAnswer(int length) {
    bool right_move;
    int left = 1, right = length, answer = ask(left, right);
    while (left != right) {
        int middle = (left + right) / 2;
        if (answer <= middle) {
            right_move = ask(1, middle) == answer;
        } else {
            right_move = ask(middle + 1, length) != answer;
        }

        if (right_move) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return left;
}

int main() {
    int length;
    std::cin >> length;
    int answer = getAnswer(length);
    std::cout<< "! " << answer << std::endl << std::flush;
    return 0;
}
