#include <iostream>
#include <vector>
#include <stack>

int main() {
    int count, new_height, last_index;
    uint64_t current, maximum = 0;
    std::stack<int> heights_stack, index_stack;

    std::cin >> count;
    for (int index = 0; index < count + 2; ++index) {
        if (index == 0) {
            new_height = -1;
        } else if (index == count + 1) {
            new_height = 0;
        } else {
            std::cin >> new_height;
        }

        last_index = index;
        while (!heights_stack.empty() && heights_stack.top() >= new_height) {
            current = heights_stack.top() * (index - index_stack.top());
            if (current > maximum) {
                maximum = current;
            }
            last_index = index_stack.top();
            heights_stack.pop();
            index_stack.pop();
        }

        heights_stack.push(new_height);
        index_stack.push(last_index);
    }

    std::cout << maximum;
    return 0;
}
