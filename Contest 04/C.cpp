#include <iostream>
#include <vector>

struct Drone {
    int id;
    int capacity;

    Drone(int id, int capacity) {
        this->id = id;
        this->capacity = capacity;
    }
};

void countSort(std::vector<Drone> *vector, std::vector<std::vector<Drone>> *answer) {
    for (auto drone : *vector) {
        (*answer)[drone.capacity].push_back(drone);
    }
}

void printVector(const std::vector<std::vector<Drone>> &vector) {
    for (int i = vector.size() - 1; i > -1; --i) {
        for (auto drone : vector[i]) {
            std::cout << drone.id << " " << drone.capacity << "\n";
        }
    }
    std::cout << "\n";
}

int main() {
    int length, id, capacity;
    std::vector<Drone> vector;
    std::vector<std::vector<Drone>> answer(1'000'000'000);
    std::cin >> length;
    for (int i = 0; i < length; ++i) {
        std::cin >> id >> capacity;
        vector.push_back(Drone(id, capacity));
    }

    countSort(&vector, &answer);
    printVector(answer);
    return 0;
}
